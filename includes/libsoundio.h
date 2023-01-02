/*
  * Copyright (c) 2015 Andrew Kelley
  *
  * This file is part of libsoundio, which is MIT licensed.
  * See http://opensource.org/licenses/MIT
  */

 #ifndef SOUNDIO_SOUNDIO_H
 #define SOUNDIO_SOUNDIO_H

 #include "endian.h"


 #ifdef __cplusplus
 #define SOUNDIO_EXTERN_C extern "C"
 #else
 #define SOUNDIO_EXTERN_C
 #endif

 #if defined(SOUNDIO_STATIC_LIBRARY)
 # define SOUNDIO_EXPORT SOUNDIO_EXTERN_C
 #else
 # if defined(_WIN32)
 #  if defined(SOUNDIO_BUILDING_LIBRARY)
 #   define SOUNDIO_EXPORT SOUNDIO_EXTERN_C __declspec(dllexport)
 #  else
 #   define SOUNDIO_EXPORT SOUNDIO_EXTERN_C __declspec(dllimport)
 #  endif
 # else
 #  define SOUNDIO_EXPORT SOUNDIO_EXTERN_C __attribute__((visibility ("default")))
 # endif
 #endif

 enum SoundIoError {
     SoundIoErrorNone,
     SoundIoErrorNoMem,
     SoundIoErrorInitAudioBackend,
     SoundIoErrorSystemResources,
     SoundIoErrorOpeningDevice,
     SoundIoErrorNoSuchDevice,
     SoundIoErrorInvalid,
     SoundIoErrorBackendUnavailable,
     SoundIoErrorStreaming,
     SoundIoErrorIncompatibleDevice,
     SoundIoErrorNoSuchClient,
     SoundIoErrorIncompatibleBackend,
     SoundIoErrorBackendDisconnected,
     SoundIoErrorInterrupted,
     SoundIoErrorUnderflow,
     SoundIoErrorEncodingString,
 };

 enum SoundIoChannelId {
     SoundIoChannelIdInvalid,

     SoundIoChannelIdFrontLeft,
     SoundIoChannelIdFrontRight,
     SoundIoChannelIdFrontCenter,
     SoundIoChannelIdLfe,
     SoundIoChannelIdBackLeft,
     SoundIoChannelIdBackRight,
     SoundIoChannelIdFrontLeftCenter,
     SoundIoChannelIdFrontRightCenter,
     SoundIoChannelIdBackCenter,
     SoundIoChannelIdSideLeft,
     SoundIoChannelIdSideRight,
     SoundIoChannelIdTopCenter,
     SoundIoChannelIdTopFrontLeft,
     SoundIoChannelIdTopFrontCenter,
     SoundIoChannelIdTopFrontRight,
     SoundIoChannelIdTopBackLeft,
     SoundIoChannelIdTopBackCenter,
     SoundIoChannelIdTopBackRight,

     SoundIoChannelIdBackLeftCenter,
     SoundIoChannelIdBackRightCenter,
     SoundIoChannelIdFrontLeftWide,
     SoundIoChannelIdFrontRightWide,
     SoundIoChannelIdFrontLeftHigh,
     SoundIoChannelIdFrontCenterHigh,
     SoundIoChannelIdFrontRightHigh,
     SoundIoChannelIdTopFrontLeftCenter,
     SoundIoChannelIdTopFrontRightCenter,
     SoundIoChannelIdTopSideLeft,
     SoundIoChannelIdTopSideRight,
     SoundIoChannelIdLeftLfe,
     SoundIoChannelIdRightLfe,
     SoundIoChannelIdLfe2,
     SoundIoChannelIdBottomCenter,
     SoundIoChannelIdBottomLeftCenter,
     SoundIoChannelIdBottomRightCenter,

     SoundIoChannelIdMsMid,
     SoundIoChannelIdMsSide,

     SoundIoChannelIdAmbisonicW,
     SoundIoChannelIdAmbisonicX,
     SoundIoChannelIdAmbisonicY,
     SoundIoChannelIdAmbisonicZ,

     SoundIoChannelIdXyX,
     SoundIoChannelIdXyY,

     SoundIoChannelIdHeadphonesLeft,
     SoundIoChannelIdHeadphonesRight,
     SoundIoChannelIdClickTrack,
     SoundIoChannelIdForeignLanguage,
     SoundIoChannelIdHearingImpaired,
     SoundIoChannelIdNarration,
     SoundIoChannelIdHaptic,
     SoundIoChannelIdDialogCentricMix,

     SoundIoChannelIdAux,
     SoundIoChannelIdAux0,
     SoundIoChannelIdAux1,
     SoundIoChannelIdAux2,
     SoundIoChannelIdAux3,
     SoundIoChannelIdAux4,
     SoundIoChannelIdAux5,
     SoundIoChannelIdAux6,
     SoundIoChannelIdAux7,
     SoundIoChannelIdAux8,
     SoundIoChannelIdAux9,
     SoundIoChannelIdAux10,
     SoundIoChannelIdAux11,
     SoundIoChannelIdAux12,
     SoundIoChannelIdAux13,
     SoundIoChannelIdAux14,
     SoundIoChannelIdAux15,
 };

 enum SoundIoChannelLayoutId {
     SoundIoChannelLayoutIdMono,
     SoundIoChannelLayoutIdStereo,
     SoundIoChannelLayoutId2Point1,
     SoundIoChannelLayoutId3Point0,
     SoundIoChannelLayoutId3Point0Back,
     SoundIoChannelLayoutId3Point1,
     SoundIoChannelLayoutId4Point0,
     SoundIoChannelLayoutIdQuad,
     SoundIoChannelLayoutIdQuadSide,
     SoundIoChannelLayoutId4Point1,
     SoundIoChannelLayoutId5Point0Back,
     SoundIoChannelLayoutId5Point0Side,
     SoundIoChannelLayoutId5Point1,
     SoundIoChannelLayoutId5Point1Back,
     SoundIoChannelLayoutId6Point0Side,
     SoundIoChannelLayoutId6Point0Front,
     SoundIoChannelLayoutIdHexagonal,
     SoundIoChannelLayoutId6Point1,
     SoundIoChannelLayoutId6Point1Back,
     SoundIoChannelLayoutId6Point1Front,
     SoundIoChannelLayoutId7Point0,
     SoundIoChannelLayoutId7Point0Front,
     SoundIoChannelLayoutId7Point1,
     SoundIoChannelLayoutId7Point1Wide,
     SoundIoChannelLayoutId7Point1WideBack,
     SoundIoChannelLayoutIdOctagonal,
 };

 enum SoundIoBackend {
     SoundIoBackendNone,
     SoundIoBackendJack,
     SoundIoBackendPulseAudio,
     SoundIoBackendAlsa,
     SoundIoBackendCoreAudio,
     SoundIoBackendWasapi,
     SoundIoBackendDummy,
 };

 enum SoundIoDeviceAim {
     SoundIoDeviceAimInput,
     SoundIoDeviceAimOutput,
 };

 enum SoundIoFormat {
     SoundIoFormatInvalid,
     SoundIoFormatS8,
     SoundIoFormatU8,
     SoundIoFormatS16LE,
     SoundIoFormatS16BE,
     SoundIoFormatU16LE,
     SoundIoFormatU16BE,
     SoundIoFormatS24LE,
     SoundIoFormatS24BE,
     SoundIoFormatU24LE,
     SoundIoFormatU24BE,
     SoundIoFormatS32LE,
     SoundIoFormatS32BE,
     SoundIoFormatU32LE,
     SoundIoFormatU32BE,
     SoundIoFormatFloat32LE,
     SoundIoFormatFloat32BE,
     SoundIoFormatFloat64LE,
     SoundIoFormatFloat64BE,
 };

 #if defined(SOUNDIO_OS_BIG_ENDIAN)
 #define SoundIoFormatS16NE SoundIoFormatS16BE
 #define SoundIoFormatU16NE SoundIoFormatU16BE
 #define SoundIoFormatS24NE SoundIoFormatS24BE
 #define SoundIoFormatU24NE SoundIoFormatU24BE
 #define SoundIoFormatS32NE SoundIoFormatS32BE
 #define SoundIoFormatU32NE SoundIoFormatU32BE
 #define SoundIoFormatFloat32NE SoundIoFormatFloat32BE
 #define SoundIoFormatFloat64NE SoundIoFormatFloat64BE

 #define SoundIoFormatS16FE SoundIoFormatS16LE
 #define SoundIoFormatU16FE SoundIoFormatU16LE
 #define SoundIoFormatS24FE SoundIoFormatS24LE
 #define SoundIoFormatU24FE SoundIoFormatU24LE
 #define SoundIoFormatS32FE SoundIoFormatS32LE
 #define SoundIoFormatU32FE SoundIoFormatU32LE
 #define SoundIoFormatFloat32FE SoundIoFormatFloat32LE
 #define SoundIoFormatFloat64FE SoundIoFormatFloat64LE

 #elif defined(SOUNDIO_OS_LITTLE_ENDIAN)

 #define SoundIoFormatS16NE SoundIoFormatS16LE
 #define SoundIoFormatU16NE SoundIoFormatU16LE
 #define SoundIoFormatS24NE SoundIoFormatS24LE
 #define SoundIoFormatU24NE SoundIoFormatU24LE
 #define SoundIoFormatS32NE SoundIoFormatS32LE
 #define SoundIoFormatU32NE SoundIoFormatU32LE
 #define SoundIoFormatFloat32NE SoundIoFormatFloat32LE
 #define SoundIoFormatFloat64NE SoundIoFormatFloat64LE

 #define SoundIoFormatS16FE SoundIoFormatS16BE
 #define SoundIoFormatU16FE SoundIoFormatU16BE
 #define SoundIoFormatS24FE SoundIoFormatS24BE
 #define SoundIoFormatU24FE SoundIoFormatU24BE
 #define SoundIoFormatS32FE SoundIoFormatS32BE
 #define SoundIoFormatU32FE SoundIoFormatU32BE
 #define SoundIoFormatFloat32FE SoundIoFormatFloat32BE
 #define SoundIoFormatFloat64FE SoundIoFormatFloat64BE

 #endif

 #define SOUNDIO_MAX_CHANNELS 24
 struct SoundIoChannelLayout {
     const char *name;
     int channel_count;
     enum SoundIoChannelId channels[SOUNDIO_MAX_CHANNELS];
 };

 struct SoundIoSampleRateRange {
     int min;
     int max;
 };

 struct SoundIoChannelArea {
     char *ptr;
     int step;
 };

 struct SoundIo {
     void *userdata;
     void (*on_devices_change)(struct SoundIo *);
     void (*on_backend_disconnect)(struct SoundIo *, int err);
     void (*on_events_signal)(struct SoundIo *);

     enum SoundIoBackend current_backend;

     const char *app_name;

     void (*emit_rtprio_warning)(void);

     void (*jack_info_callback)(const char *msg);
     void (*jack_error_callback)(const char *msg);
 };

 struct SoundIoDevice {
     struct SoundIo *soundio;

     char *id;
     char *name;

     enum SoundIoDeviceAim aim;

     struct SoundIoChannelLayout *layouts;
     int layout_count;
     struct SoundIoChannelLayout current_layout;

     enum SoundIoFormat *formats;
     int format_count;
     enum SoundIoFormat current_format;

     struct SoundIoSampleRateRange *sample_rates;
     int sample_rate_count;
     int sample_rate_current;

     double software_latency_min;
     double software_latency_max;
     double software_latency_current;

     bool is_raw;

     int ref_count;

     int probe_error;
 };

 struct SoundIoOutStream {
     struct SoundIoDevice *device;

     enum SoundIoFormat format;

     int sample_rate;

     struct SoundIoChannelLayout layout;

     double software_latency;
     float volume;
     void *userdata;
     void (*write_callback)(struct SoundIoOutStream *,
             int frame_count_min, int frame_count_max);
     void (*underflow_callback)(struct SoundIoOutStream *);
     void (*error_callback)(struct SoundIoOutStream *, int err);

     const char *name;

     bool non_terminal_hint;


     int bytes_per_frame;
     int bytes_per_sample;

     int layout_error;
 };

 struct SoundIoInStream {
     struct SoundIoDevice *device;

     enum SoundIoFormat format;

     int sample_rate;

     struct SoundIoChannelLayout layout;

     double software_latency;

     void *userdata;
     void (*read_callback)(struct SoundIoInStream *, int frame_count_min, int frame_count_max);
     void (*overflow_callback)(struct SoundIoInStream *);
     void (*error_callback)(struct SoundIoInStream *, int err);

     const char *name;

     bool non_terminal_hint;

     int bytes_per_frame;
     int bytes_per_sample;

     int layout_error;
 };

 SOUNDIO_EXPORT const char *soundio_version_string(void);
 SOUNDIO_EXPORT int soundio_version_major(void);
 SOUNDIO_EXPORT int soundio_version_minor(void);
 SOUNDIO_EXPORT int soundio_version_patch(void);

 SOUNDIO_EXPORT struct SoundIo *soundio_create(void);
 SOUNDIO_EXPORT void soundio_destroy(struct SoundIo *soundio);


 SOUNDIO_EXPORT int soundio_connect(struct SoundIo *soundio);
 SOUNDIO_EXPORT int soundio_connect_backend(struct SoundIo *soundio, enum SoundIoBackend backend);
 SOUNDIO_EXPORT void soundio_disconnect(struct SoundIo *soundio);

 SOUNDIO_EXPORT const char *soundio_strerror(int error);
 SOUNDIO_EXPORT const char *soundio_backend_name(enum SoundIoBackend backend);

 SOUNDIO_EXPORT int soundio_backend_count(struct SoundIo *soundio);
 SOUNDIO_EXPORT enum SoundIoBackend soundio_get_backend(struct SoundIo *soundio, int index);

 SOUNDIO_EXPORT bool soundio_have_backend(enum SoundIoBackend backend);

 SOUNDIO_EXPORT void soundio_flush_events(struct SoundIo *soundio);

 SOUNDIO_EXPORT void soundio_wait_events(struct SoundIo *soundio);

 SOUNDIO_EXPORT void soundio_wakeup(struct SoundIo *soundio);


 SOUNDIO_EXPORT void soundio_force_device_scan(struct SoundIo *soundio);


 // Channel Layouts

 SOUNDIO_EXPORT bool soundio_channel_layout_equal(
         const struct SoundIoChannelLayout *a,
         const struct SoundIoChannelLayout *b);

 SOUNDIO_EXPORT const char *soundio_get_channel_name(enum SoundIoChannelId id);
 SOUNDIO_EXPORT enum SoundIoChannelId soundio_parse_channel_id(const char *str, int str_len);

 SOUNDIO_EXPORT int soundio_channel_layout_builtin_count(void);
 SOUNDIO_EXPORT const struct SoundIoChannelLayout *soundio_channel_layout_get_builtin(int index);

 SOUNDIO_EXPORT const struct SoundIoChannelLayout *soundio_channel_layout_get_default(int channel_count);

 SOUNDIO_EXPORT int soundio_channel_layout_find_channel(
         const struct SoundIoChannelLayout *layout, enum SoundIoChannelId channel);

 SOUNDIO_EXPORT bool soundio_channel_layout_detect_builtin(struct SoundIoChannelLayout *layout);

 SOUNDIO_EXPORT const struct SoundIoChannelLayout *soundio_best_matching_channel_layout(
         const struct SoundIoChannelLayout *preferred_layouts, int preferred_layout_count,
         const struct SoundIoChannelLayout *available_layouts, int available_layout_count);

 SOUNDIO_EXPORT void soundio_sort_channel_layouts(struct SoundIoChannelLayout *layouts, int layout_count);


 // Sample Formats

 SOUNDIO_EXPORT int soundio_get_bytes_per_sample(enum SoundIoFormat format);

 static inline int soundio_get_bytes_per_frame(enum SoundIoFormat format, int channel_count) {
     return soundio_get_bytes_per_sample(format) * channel_count;
 }

 static inline int soundio_get_bytes_per_second(enum SoundIoFormat format,
         int channel_count, int sample_rate)
 {
     return soundio_get_bytes_per_frame(format, channel_count) * sample_rate;
 }

 SOUNDIO_EXPORT const char * soundio_format_string(enum SoundIoFormat format);




 // Devices


 SOUNDIO_EXPORT int soundio_input_device_count(struct SoundIo *soundio);
 SOUNDIO_EXPORT int soundio_output_device_count(struct SoundIo *soundio);

 SOUNDIO_EXPORT struct SoundIoDevice *soundio_get_input_device(struct SoundIo *soundio, int index);
 SOUNDIO_EXPORT struct SoundIoDevice *soundio_get_output_device(struct SoundIo *soundio, int index);

 SOUNDIO_EXPORT int soundio_default_input_device_index(struct SoundIo *soundio);

 SOUNDIO_EXPORT int soundio_default_output_device_index(struct SoundIo *soundio);

 SOUNDIO_EXPORT void soundio_device_ref(struct SoundIoDevice *device);
 SOUNDIO_EXPORT void soundio_device_unref(struct SoundIoDevice *device);

 SOUNDIO_EXPORT bool soundio_device_equal(
         const struct SoundIoDevice *a,
         const struct SoundIoDevice *b);

 SOUNDIO_EXPORT void soundio_device_sort_channel_layouts(struct SoundIoDevice *device);

 SOUNDIO_EXPORT bool soundio_device_supports_format(struct SoundIoDevice *device,
         enum SoundIoFormat format);

 SOUNDIO_EXPORT bool soundio_device_supports_layout(struct SoundIoDevice *device,
         const struct SoundIoChannelLayout *layout);

 SOUNDIO_EXPORT bool soundio_device_supports_sample_rate(struct SoundIoDevice *device,
         int sample_rate);

 SOUNDIO_EXPORT int soundio_device_nearest_sample_rate(struct SoundIoDevice *device,
         int sample_rate);



 // Output Streams
 SOUNDIO_EXPORT struct SoundIoOutStream *soundio_outstream_create(struct SoundIoDevice *device);
 SOUNDIO_EXPORT void soundio_outstream_destroy(struct SoundIoOutStream *outstream);

 SOUNDIO_EXPORT int soundio_outstream_open(struct SoundIoOutStream *outstream);

 SOUNDIO_EXPORT int soundio_outstream_start(struct SoundIoOutStream *outstream);

 SOUNDIO_EXPORT int soundio_outstream_begin_write(struct SoundIoOutStream *outstream,
         struct SoundIoChannelArea **areas, int *frame_count);

 SOUNDIO_EXPORT int soundio_outstream_end_write(struct SoundIoOutStream *outstream);

 SOUNDIO_EXPORT int soundio_outstream_clear_buffer(struct SoundIoOutStream *outstream);

 SOUNDIO_EXPORT int soundio_outstream_pause(struct SoundIoOutStream *outstream, bool pause);

 SOUNDIO_EXPORT int soundio_outstream_get_latency(struct SoundIoOutStream *outstream,
         double *out_latency);

 SOUNDIO_EXPORT int soundio_outstream_set_volume(struct SoundIoOutStream *outstream,
         double volume);



 // Input Streams
 SOUNDIO_EXPORT struct SoundIoInStream *soundio_instream_create(struct SoundIoDevice *device);
 SOUNDIO_EXPORT void soundio_instream_destroy(struct SoundIoInStream *instream);

 SOUNDIO_EXPORT int soundio_instream_open(struct SoundIoInStream *instream);

 SOUNDIO_EXPORT int soundio_instream_start(struct SoundIoInStream *instream);

 SOUNDIO_EXPORT int soundio_instream_begin_read(struct SoundIoInStream *instream,
         struct SoundIoChannelArea **areas, int *frame_count);
 SOUNDIO_EXPORT int soundio_instream_end_read(struct SoundIoInStream *instream);

 SOUNDIO_EXPORT int soundio_instream_pause(struct SoundIoInStream *instream, bool pause);

 SOUNDIO_EXPORT int soundio_instream_get_latency(struct SoundIoInStream *instream,
         double *out_latency);


 struct SoundIoRingBuffer;

 SOUNDIO_EXPORT struct SoundIoRingBuffer *soundio_ring_buffer_create(struct SoundIo *soundio, int requested_capacity);
 SOUNDIO_EXPORT void soundio_ring_buffer_destroy(struct SoundIoRingBuffer *ring_buffer);

 SOUNDIO_EXPORT int soundio_ring_buffer_capacity(struct SoundIoRingBuffer *ring_buffer);

 SOUNDIO_EXPORT char *soundio_ring_buffer_write_ptr(struct SoundIoRingBuffer *ring_buffer);
 SOUNDIO_EXPORT void soundio_ring_buffer_advance_write_ptr(struct SoundIoRingBuffer *ring_buffer, int count);

 SOUNDIO_EXPORT char *soundio_ring_buffer_read_ptr(struct SoundIoRingBuffer *ring_buffer);
 SOUNDIO_EXPORT void soundio_ring_buffer_advance_read_ptr(struct SoundIoRingBuffer *ring_buffer, int count);

 SOUNDIO_EXPORT int soundio_ring_buffer_fill_count(struct SoundIoRingBuffer *ring_buffer);

 SOUNDIO_EXPORT int soundio_ring_buffer_free_count(struct SoundIoRingBuffer *ring_buffer);

 SOUNDIO_EXPORT void soundio_ring_buffer_clear(struct SoundIoRingBuffer *ring_buffer);

 #endif
