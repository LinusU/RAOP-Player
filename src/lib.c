#include "log_util.h"

log_level	util_loglevel = lSDEBUG;
log_level	raop_loglevel = lSDEBUG;
log_level 	main_log = lSDEBUG;

log_level *loglevel =&main_log;

/*----------------------------------------------------------------------------*/
__u64 get_ntp(struct ntp_s *ntp)
{
	struct timeval ctv;
	struct ntp_s local;

	gettimeofday(&ctv, NULL);
	local.seconds  = ctv.tv_sec + 0x83AA7E80;
	local.fraction = (((__u64) ctv.tv_usec) << 32) / 1000000;

	if (ntp) *ntp = local;

	return (((__u64) local.seconds) << 32) + local.fraction;
}

void lib_fd_zero(struct fd_set *set) {
	FD_ZERO(set);
}

void lib_fd_set(int fd, struct fd_set *set) {
	FD_SET(fd, set);
}

bool lib_fd_isset(int fd, struct fd_set *set) {
	return FD_ISSET(fd, set);
}
