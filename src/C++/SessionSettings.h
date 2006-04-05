/* -*- C++ -*- */

/****************************************************************************
** Copyright (c) quickfixengine.org  All rights reserved.
**
** This file is part of the QuickFIX FIX Engine
**
** This file may be distributed under the terms of the quickfixengine.org
** license as defined by quickfixengine.org and appearing in the file
** LICENSE included in the packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.quickfixengine.org/LICENSE for licensing information.
**
** Contact ask@quickfixengine.org if any conditions of this licensing are
** not clear to you.
**
****************************************************************************/

#ifndef FIX_SESSIONSETTINGS_H
#define FIX_SESSIONSETTINGS_H

#ifdef _MSC_VER
#pragma warning( disable : 4503 4355 4786 4290 )
#endif

#include "Dictionary.h"
#include "SessionID.h"
#include "Exceptions.h"
#include <map>
#include <set>

namespace FIX
{
const char BEGINSTRING[] = "BeginString";
const char SENDERCOMPID[] = "SenderCompID";
const char TARGETCOMPID[] = "TargetCompID";
const char SESSION_QUALIFIER[] = "SessionQualifier";
const char CONNECTION_TYPE[] = "ConnectionType";
const char USE_DATA_DICTIONARY[] = "UseDataDictionary";
const char SEND_RESETSEQNUMFLAG[] = "SendResetSeqNumFlag";
const char DATA_DICTIONARY[] = "DataDictionary";
const char START_TIME[] = "StartTime";
const char END_TIME[] = "EndTime";
const char START_DAY[] = "StartDay";
const char END_DAY[] = "EndDay";
const char CHECK_LATENCY[] = "CheckLatency";
const char MAX_LATENCY[] = "MaxLatency";
const char HEARTBTINT[] = "HeartBtInt";
const char SOCKET_ACCEPT_PORT[] = "SocketAcceptPort";
const char SOCKET_REUSE_ADDRESS[] = "SocketReuseAddress";
const char SOCKET_CONNECT_HOST[] = "SocketConnectHost";
const char SOCKET_CONNECT_PORT[] = "SocketConnectPort";
const char SOCKET_NODELAY[] = "SocketNodelay";
const char RECONNECT_INTERVAL[] = "ReconnectInterval";
const char VALIDATE_FIELDS_OUT_OF_ORDER[] = "ValidateFieldsOutOfOrder";
const char VALIDATE_FIELDS_HAVE_VALUES[] = "ValidateFieldsHaveValues";
const char VALIDATE_USER_DEFINED_FIELDS[] = "ValidateUserDefinedFields";
const char LOGON_TIMEOUT[] = "LogonTimeout";
const char LOGOUT_TIMEOUT[] = "LogoutTimeout";
const char FILE_PATH[] = "FilePath";
const char FILE_STORE_PATH[] = "FileStorePath";
const char MYSQL_STORE_USECONNECTIONPOOL[] = "MySQLStoreUseConnectionPool";
const char MYSQL_STORE_DATABASE[] = "MySQLStoreDatabase";
const char MYSQL_STORE_USER[] = "MySQLStoreUser";
const char MYSQL_STORE_PASSWORD[] = "MySQLStorePassword";
const char MYSQL_STORE_HOST[] = "MySQLStoreHost";
const char MYSQL_STORE_PORT[] = "MySQLStorePort";
const char MSSQL_STORE_DATABASE[] = "MSSQLStoreDatabase";
const char MSSQL_STORE_USER[] = "MSSQLStoreUser";
const char MSSQL_STORE_PASSWORD[] = "MSSQLStorePassword";
const char MSSQL_STORE_HOST[] = "MSSQLStoreHost";
const char POSTGRESQL_STORE_USECONNECTIONPOOL[] = "PostgreSQLStoreUseConnectionPool";
const char POSTGRESQL_STORE_DATABASE[] = "PostgreSQLStoreDatabase";
const char POSTGRESQL_STORE_USER[] = "PostgreSQLStoreUser";
const char POSTGRESQL_STORE_PASSWORD[] = "PostgreSQLStorePassword";
const char POSTGRESQL_STORE_HOST[] = "PostgreSQLStoreHost";
const char POSTGRESQL_STORE_PORT[] = "PostgreSQLStorePort";
const char ODBC_STORE_USER[] = "OdbcStoreUser";
const char ODBC_STORE_PASSWORD[] = "OdbcStorePassword";
const char ODBC_STORE_CONNECTION_STRING[] = "OdbcStoreConnectionString";
const char FILE_LOG_PATH[] = "FileLogPath";
const char MYSQL_LOG_USECONNECTIONPOOL[] = "MySQLLogUseConnectionPool";
const char MYSQL_LOG_DATABASE[] = "MySQLLogDatabase";
const char MYSQL_LOG_USER[] = "MySQLLogUser";
const char MYSQL_LOG_PASSWORD[] = "MySQLLogPassword";
const char MYSQL_LOG_HOST[] = "MySQLLogHost";
const char MYSQL_LOG_PORT[] = "MySQLLogPort";
const char MSSQL_LOG_DATABASE[] = "MSSQLLogDatabase";
const char MSSQL_LOG_USER[] = "MSSQLLogUser";
const char MSSQL_LOG_PASSWORD[] = "MSSQLLogPassword";
const char MSSQL_LOG_HOST[] = "MSSQLLogHost";
const char POSTGRESQL_LOG_USECONNECTIONPOOL[] = "PostgreSQLLogUseConnectionPool";
const char POSTGRESQL_LOG_DATABASE[] = "PostgreSQLLogDatabase";
const char POSTGRESQL_LOG_USER[] = "PostgreSQLLogUser";
const char POSTGRESQL_LOG_PASSWORD[] = "PostgreSQLLogPassword";
const char POSTGRESQL_LOG_HOST[] = "PostgreSQLLogHost";
const char POSTGRESQL_LOG_PORT[] = "PostgreSQLLogPort";
const char ODBC_LOG_USER[] = "OdbcLogUser";
const char ODBC_LOG_PASSWORD[] = "OdbcLogPassword";
const char ODBC_LOG_CONNECTION_STRING[] = "OdbcLogConnectionString";
const char RESET_ON_LOGOUT[] = "ResetOnLogout";
const char RESET_ON_DISCONNECT[] = "ResetOnDisconnect";
const char MILLISECONDS_IN_TIMESTAMP[] = "MillisecondsInTimeStamp";

/*! \addtogroup user
 *  @{
 */
/// Container for setting dictionaries mapped to sessions.
class SessionSettings
{
public:
  SessionSettings() {}
  SessionSettings( std::istream& stream ) throw( ConfigError );
  SessionSettings( const std::string& file ) throw( ConfigError );

  /// Get a dictionary for a session.
  const Dictionary& get( const SessionID& ) const throw( ConfigError );
  /// Set a dictionary for a session
  void set( const SessionID&, Dictionary ) throw( ConfigError );

  /// Get global default settings
  const Dictionary& get() const { return m_defaults; }
  /// Set global default settings
  void set( const Dictionary& defaults ) throw( ConfigError );

  /// Number of session settings
  int size() { return m_settings.size(); }

  typedef std::map < SessionID, Dictionary > Dictionaries;
  std::set < SessionID > getSessions() const;

private:
  void validate( const Dictionary& ) const throw( ConfigError );

  Dictionaries m_settings;
  Dictionary m_defaults;
};
/*! @} */

std::istream& operator>>( std::istream&, SessionSettings& )
throw( ConfigError );
}

#endif //FIX_SESSIONSETTINGS_H
