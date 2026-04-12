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
    uint64_t n, k;
    string s;
    cin >> n >> s >> k;

    auto c = s[k-1];

    for (uint64_t i = 0; i < n; ++i) {
	if (s[i] != c) {
	    cout << "*";
	} else {
	    cout << s[i];
	}
    }
    cout << endl;
    return 0;
}