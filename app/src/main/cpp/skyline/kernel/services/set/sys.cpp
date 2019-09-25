#include "sys.h"
#include "../../types/KProcess.h"

namespace skyline::kernel::service::set {
    sys::sys(const DeviceState &state, ServiceManager& manager) : BaseService(state, manager, false, Service::set_sys, {{0x3, SFunc(sys::GetFirmwareVersion)}}) {}

    void sys::GetFirmwareVersion(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        static SysVerTitle title{.minor=9, .major=0, .micro=0, .rev_major=4, .platform="NX", .ver_hash="4de65c071fd0869695b7629f75eb97b2551dbf2f", .disp_ver="9.0.0", .disp_title="NintendoSDK Firmware for NX 9.0.0-4.0"};
        state.thisProcess->WriteMemory(title, request.vecBufC[0]->address);
    }
}