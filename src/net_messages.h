#ifndef _DLSTORM_DEFAULT_NETWORK_MESSAGES
#define _DLSTORM_DEFAULT_NETWORK_MESSAGES

typedef enum {
    NET_FILE_START = 1,
    NET_FILE_START_OK,
    NET_FILE_ERROR,
    NET_FILE_DATA,
    NET_FILE_DATA_OK,
    NET_FILE_DATA_RESEND,
    NET_FILE_EOF,
    NET_FILE_EOF_RESEND,
    NET_FILE_RESUME,
    NET_FILE_ACK,
    NET_FILE_FILE_ABORT,
    NET_FILE_NOP,
    NET_FILE_ABORT,
} tDLSTORMNetFileMsg;

typedef enum {
    NETMSG_NOMESSAGE = 1,
    NETMSG_NOP,
    NETMSG_LOGIN_REQUEST,
    NETMSG_LOGIN_REQUEST_REPLY,
    NETMSG_LOGOUT,
    NETMSG_SYSTEMMSG,
    NETMSG_CHAT,
    NETMSG_LOCALCHAT,
    NETMSG_VIS_UPDATE,
    NETMSG_VIS_REMOVE,
    NETMSG_MOVEPLAYER,
    NETMSG_CREATE_CHARACTER,
    NETMSG_MODIFY_CHARACTER,
    NETMSG_RETRIEVECHARS,
    NETMSG_RETRIEVECHARINFO,
    NETMSG_GETINVENTORY,
    NETMSG_CHANGETILE,
    NETMSG_CHANGEOBJECT,
    NETMSG_CLIENT_SHUTDOWN,
    NETMSG_DELETE_CHARACTER,
    NETMSG_GENERIC_MSG,
    NETMSG_SET_TILE,
    NETMSG_SET_OBJECT,
    NETMSG_CHANGE_MODE,
    NETMSG_MODIFY_MAP,
    NETMSG_SET_VERTEX,
    NETMSG_HEARTBEAT,
    NETMSG_HEARTBEAT_REQUEST,
    NETMSG_CHAR_STATUS,
    NETMSG_DOWNLOAD,
    NETMSG_UPLOAD,
    NETMSG_PING,
    NETMSG_PROMPT,
    NETMSG_FVM,
    NETMSG_SERVER_INFO,
    NETMSG_PUT_SERVER_INFO,
    NETMSG_GET_SERVER_LIST,
    NETMSG_MASTER_TO_GAME,
    NETMSG_GUI,
    NETMSG_GUI_COMMAND,
    NETMSG_GUI_CALLBACK,
    NETMSG_GET_LOGIN_PROGRAM,

    NETMSG_SERVERINFORMATION,
    NETMSG_SERVERINFORMATION_GET,
    NETMSG_SERVERINFORMATION_RESET,
    NETMSG_SERVERINFORMATION_END,
    NETMSG_FILE_XFER,

} tDLSTORMNetMsg;

#endif  // _DLSTORM_DEFAULT_NETWORK_MESSAGES