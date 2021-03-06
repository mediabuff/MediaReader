#include "pch.h"

using namespace MediaCaptureReader;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Windows::Media::Capture;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::UI::Core;

TEST_CLASS(MediaGraphicsDeviceTests)
{
public:

    //
    // Windows tests use NullMediaCapture as the real MediaCapture tries to pop up a consent UI which is nowhere to be seen
    // and cannot be automatically dismissed from within the tests
    //

    TEST_METHOD(CX_W_MediaGraphicsDevice_Basic)
    {
        Await(CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(
            CoreDispatcherPriority::Normal, 
            ref new DispatchedHandler([]()
        {
            auto capture = NullMediaCapture::Create();
            Await(capture->InitializeAsync());

            auto device = MediaGraphicsDevice::CreateFromMediaCapture(capture);
            Assert::IsNotNull(device);
        })));
    }

};
