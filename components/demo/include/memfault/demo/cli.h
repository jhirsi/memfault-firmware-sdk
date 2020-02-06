#pragma once

//! @file
//!
//! Copyright (c) Memfault, Inc.
//! See License.txt for details
//!
//! @brief CLI console commands for Memfault demo apps
//!
//! The first element in argv is expected to be the command name that was invoked.
//! The elements following after that are expected to be the arguments to the command.

#ifdef __cplusplus
extern "C" {
#endif

//! Command to crash the device, for example, to trigger a coredump to be captured.
//! It takes one number argument, which is the crash type:
//! - 0: crash by MEMFAULT_ASSERT(0)
//! - 1: crash by jumping to 0xbadcafe
//! - 2: crash by unaligned memory store
int memfault_demo_cli_cmd_crash(int argc, char *argv[]);

//! Command to exercise the MEMFAULT_TRACE_EVENT API, capturing a
//! Trace Event with the error reason set to "MemfaultDemoCli_Error".
int memfault_demo_cli_cmd_trace_event_capture(int argc, char *argv[]);

//! Command to get whether a coredump is currently stored and how large it is.
//! It takes no arguments.
int memfault_demo_cli_cmd_get_core(int argc, char *argv[]);

//! Command to post a coredump using the http client.
//! It takes no arguments.
int memfault_demo_cli_cmd_post_core(int argc, char *argv[]);

//! Command to print out the next Memfault data to send and print as a curl command.
//! It takes zero or one string argument, which can be:
//! - curl : (default) prints a shell command to post the next data chunk to Memfault's API (using echo, xxd and curl)
//! - hex : hexdumps the data
int memfault_demo_cli_cmd_print_chunk(int argc, char *argv[]);

//! Command to clear a coredump.
//! It takes no arguments.
int memfault_demo_cli_cmd_clear_core(int argc, char *argv[]);

//! Command to print device info, as obtained through memfault_platform_get_device_info().
//! It takes no arguments.
int memfault_demo_cli_cmd_get_device_info(int argc, char *argv[]);

#ifdef __cplusplus
}
#endif
