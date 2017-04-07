/*
 * ddsbrick.h
 *
 *  Created on: Apr 9, 2017
 *      Author: neal
 */

#ifndef YCSB_C_DDSBRICK_H_
#define YCSB_C_DDSBRICK_H_

#include "kvdb.h"

namespace Ycsb {
namespace DB {

class DDSBrick: public KVDB {
public:
	DDSBrick() {
		shareDB = false;
		poolCached = true;
	}

	DDSBrick(const DDSBrick& other)
			: KVDB(other) {
		ips_ = other.ips_;
		selfAddress_ = other.selfAddress_;
		clients_ = other.clients_;
		poolCached = other.poolCached;
	}

	virtual ~DDSBrick() {
	}

	void EnablePoolCache() {
		poolCached = true;
	}

	void DisablePoolCache() {
		poolCached = false;
	}

protected:
	/*
	 * poolCached means whether RTree enables the de-serialized mempool cache
	 */
	bool poolCached;

	std::unordered_map<std::string, DTranx::Client::Client*> clients_;
	std::vector<std::string> ips_;
	std::string selfAddress_;
};
} // DB
} // Ycsb

#endif /* YCSB_C_DDSBRICK_H_ */
