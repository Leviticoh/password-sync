#ifndef PWD_CONN_MNGR
#define PWD_CONN_MNGR

struct Peer{
	char* hostname;
	char* timestamp;
	struct peer* next;
};

typedef Peer* PeerList;

PeerList CM_ReachablePeers();

void CM_outdatedPeers(PeerList*, char*);

#endif
