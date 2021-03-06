#ifndef DBUSHANDLER_H
#define DBUSHANDLER_H

#include "appconf.h"
#include <dbus/dbus.h>
#include <string>

class DBusHandler
{
public:
    DBusHandler(const AppConf::DBusParamsStruct & params);

    bool Init();
    bool MethodCall(const char * target, const char * object, const char * interface, const char * method, DBusPendingCall * & pending);
    bool PropertyRequest(const char * target, const char * object, const char * interface, const char * property, DBusPendingCall * & pending);
    bool GetReply(DBusPendingCall* & pending, DBusMessage* & msg);
    std::string GetString(DBusMessageIter &iter);
    int GetInt(DBusMessageIter & iter);

private:
    DBusConnection* conn;
    bool isConnected;
    AppConf::DBusParamsStruct _params;
};

#endif // DBUSHANDLER_H
