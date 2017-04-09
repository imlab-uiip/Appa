// Copyright 2017 Lybros.

#ifndef SRC_STORAGE_H_
#define SRC_STORAGE_H_

#include <iostream>

#include <QtAlgorithms>
#include <QDirIterator>
#include <QFileInfo>
#include <QVector>

#include <theia/theia.h>

#include <glog/logging.h>
#include "options.h"

using theia::Reconstruction;

// The pattern may be extended with image extensions which are supported
// by Theia.
const QString IMAGE_FILENAME_PATTERN = "\\b.(jpg|JPG|jpeg|JPEG|png|PNG)";

class Storage {
 public:
  Storage();

  explicit Storage(QString images_path);

  QString GetImagesPath();

  // Returns the number of images parsed from new source.
  int UpdateImagesPath(QString images_path);

  // In case we load the project - we want to be sure we're only adding
  // the images we've had before. This method allows to avoid parsing and
  // put only the images we pass.
  // Verification than will check if the images are still exist.
  bool ForceInitialize(QString images_path, const QVector<QString>& images);

  // Returns the number of images parsed.
  int ParseImageFolder();

  int NumberOfImages();

  QVector<QString>& GetImages();

  ~Storage();

  void SetReconstructionStatus(ReconstructionStatus status);

 private:
 public:
  std::vector<std::shared_ptr<Reconstruction>>& GetReconstructions();

  void SetReconstructions(std::vector<Reconstruction*> reconstructions);

  ReconstructionStatus GetReconstructionStatus() const;

 private:
  std::vector<std::shared_ptr<Reconstruction>> reconstructions_;
  QVector<QString>* images_;
  QString images_path_;
  ReconstructionStatus status_;
};

#endif  // SRC_STORAGE_H_
