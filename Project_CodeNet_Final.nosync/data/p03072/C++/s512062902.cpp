#include <iostream>
#include <set>
#include <list>
#include <utility>
#include <queue>
#include <memory>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std; 

int
main(int argc, char const *argv[])
{
    uint64_t t, i, j, min, res;
    cin >> t;

    vector<uint64_t> hs;
    for (uint64_t i = 0; i < t; ++i) {
	uint64_t v;
	cin >> v;
	hs.push_back(v);
    }

    min = 0;
    res = 0;

    for (auto h = hs.begin(); h != hs.end(); ++h) {
	if (*h >= min) {
	    ++res;
	    min = *h;
	}
    }

    cout << res << endl;

    return 0;
}
