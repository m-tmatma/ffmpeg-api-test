/*!
    @file

    ffmpeg test program for device enum
*/
#include <stdio.h>
#include <libavformat/avformat.h>
#include <libavdevice/avdevice.h>


static void enum_input_devices()
{

    AVInputFormat *fmt = NULL;
    while (1)
    {
        fmt = av_input_audio_device_next(fmt);
        if (fmt == NULL)
        {
            break;
        }
        printf("name = %-10s, long_name = %s, mime_type = %s\n", fmt->name, fmt->long_name, fmt->mime_type);

        AVDeviceInfoList* device_list = NULL;
        int ret = avdevice_list_input_sources(
            fmt,
            NULL, // device_name
            NULL, // device_options
            &device_list
        );
        if (ret >= 0)
        {
            printf("avdevice_list_input_sources returns %d\n", ret);
        }
        avdevice_free_list_devices(&device_list);
        device_list = NULL;
    }
}

int main()
{
    avdevice_register_all();

    printf("---------------------------------------------------------\n");
    printf("avdevice_configuration: %s\n", avdevice_configuration());
    printf("---------------------------------------------------------\n");
    printf("avdevice_license: %s\n", avdevice_license());
    printf("---------------------------------------------------------\n");
    printf("avdevice_version : %x\n", avdevice_version());
    printf("---------------------------------------------------------\n");

    enum_input_devices();
    return 0;
}
