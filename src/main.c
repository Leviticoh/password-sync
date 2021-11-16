#include<unistd.h>

#include<conn_manager.h>
#include<data_carrier.h>
#include<stor_manager.h>

int main(int argc, char** argv)
{
	char* prefix = "/tmp/dbbackups/";
	char* db_path = "/tmp/db.kdbx";

	PeerList peers = CM_reachablePeers();
	char* timestamp = SM_update();
	CM_outdatedPeers(&peers, timestamp);
	char* path = SM_getPath(timestamp, prefix);
	DC_sendUpdate(peers, path);
}
