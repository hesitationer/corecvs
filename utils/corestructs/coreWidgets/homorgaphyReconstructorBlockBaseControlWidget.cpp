/**
 * \file homorgaphyReconstructorBlockBaseControlWidget.cpp
 * \attention This file is automatically generated and should not be in general modified manually
 *
 * \date MMM DD, 20YY
 * \author autoGenerator
 */

#include "homorgaphyReconstructorBlockBaseControlWidget.h"
#include "ui_homorgaphyReconstructorBlockBaseControlWidget.h"
#include <memory>
#include "qSettingsGetter.h"
#include "qSettingsSetter.h"


HomorgaphyReconstructorBlockBaseControlWidget::HomorgaphyReconstructorBlockBaseControlWidget(QWidget *parent, bool _autoInit, QString _rootPath)
    : ParametersControlWidgetBase(parent)
    , mUi(new Ui::HomorgaphyReconstructorBlockBaseControlWidget)
    , autoInit(_autoInit)
    , rootPath(_rootPath)
{
    mUi->setupUi(this);

    QObject::connect(mUi->algorithmComboBox, SIGNAL(currentIndexChanged(int)), this, SIGNAL(paramsChanged()));
}

HomorgaphyReconstructorBlockBaseControlWidget::~HomorgaphyReconstructorBlockBaseControlWidget()
{

    delete mUi;
}

void HomorgaphyReconstructorBlockBaseControlWidget::loadParamWidget(WidgetLoader &loader)
{
    std::unique_ptr<HomorgaphyReconstructorBlockBase> params(createParameters());
    loader.loadParameters(*params, rootPath);
    setParameters(*params);
}

void HomorgaphyReconstructorBlockBaseControlWidget::saveParamWidget(WidgetSaver  &saver)
{
    saver.saveParameters(*std::unique_ptr<HomorgaphyReconstructorBlockBase>(createParameters()), rootPath);
}

void HomorgaphyReconstructorBlockBaseControlWidget::getParameters(HomorgaphyReconstructorBlockBase& params) const
{
    params = *std::unique_ptr<HomorgaphyReconstructorBlockBase>(createParameters());
}


HomorgaphyReconstructorBlockBase *HomorgaphyReconstructorBlockBaseControlWidget::createParameters() const
{

    /**
     * We should think of returning parameters by value or saving them in a preallocated place
     **/


    return new HomorgaphyReconstructorBlockBase(
          NULL
        , NULL
        , static_cast<HomographyAlgorithm::HomographyAlgorithm>(mUi->algorithmComboBox->currentIndex())
    );
}

void HomorgaphyReconstructorBlockBaseControlWidget::setParameters(const HomorgaphyReconstructorBlockBase &input)
{
    // Block signals to send them all at once
    bool wasBlocked = blockSignals(true);
    mUi->algorithmComboBox->setCurrentIndex(input.algorithm());
    blockSignals(wasBlocked);
    emit paramsChanged();
}

void HomorgaphyReconstructorBlockBaseControlWidget::setParametersVirtual(void *input)
{
    // Modify widget parameters from outside
    HomorgaphyReconstructorBlockBase *inputCasted = static_cast<HomorgaphyReconstructorBlockBase *>(input);
    setParameters(*inputCasted);
}
