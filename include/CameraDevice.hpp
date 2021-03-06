////////////////////////////////////////////////////////////////////////////////
//
// Copyright Intel Corporation All Rights Reserved.
//
// The source code, information and material ("Material") contained herein is
// owned by Intel Corporation or its suppliers or licensors, and title to such
// Material remains with Intel Corporation or its suppliers or licensors. The
// Material contains proprietary information of Intel or its suppliers and
// licensors. The Material is protected by worldwide copyright laws and treaty
// provisions. No part of the Material may be used, copied, reproduced,
// modified, published, uploaded, posted, transmitted, distributed or disclosed
// in any way without Intel's prior express written permission. No license under
// any patent, copyright or other intellectual property rights in the Material
// is granted to or conferred upon you, either expressly, by implication,
// inducement, estoppel or otherwise. Any license under such intellectual
// property rights must be express and approved by Intel in writing.
//
// Unless otherwise agreed by Intel in writing, you may not remove or alter this
// notice or any other notice embedded in Materials by Intel or Intel's
// suppliers or licensors in any way."
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "OutputDevice.hpp"
#include "GStreamerApp.hpp"
#include "Configuration.hpp"


namespace earlyapp
{
    /*
      CameraDevice
      : A class abstracts camera device.
     */
    class CameraDevice: public OutputDevice, GStreamerApp
    {
    public:
        static CameraDevice* getInstance(void);

        void init(std::shared_ptr<Configuration> pConf);

        void play(void);

        void stop(void);

        void terminate(void);

        virtual ~CameraDevice(void);

    protected:
        /*
          Create a camera pipeline.
         */
        virtual GstElement* createPipeline(std::shared_ptr<Configuration> pConf);

    private:
        // Hide the default constructor to prevent instancitating.
        CameraDevice(void) { }

        // User set configurations.
        static CameraDevice* m_pCDev;

        // user configuration.
        std::shared_ptr<Configuration> m_pConf;

        /*
          GStreamer elements.
         */
        GstElement* m_pCamSrc = nullptr;
        GstElement* m_pCamSink = nullptr;
        GstElement* m_pPostProc = nullptr;
        GstElement* m_pScale = nullptr;
        GstElement* m_pScaleFilter = nullptr;
    };
} // namespace
