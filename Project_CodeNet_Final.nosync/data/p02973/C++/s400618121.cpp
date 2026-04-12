#ifdef OJ_MISC_OFFLINE

#include "prolog.h"

#else
#define PRINT
#define LCERR
#endif

#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace {

using namespace std;

class Solution {
public:
    int sequence_decomposing(const vector<int>& a) {
        vector<int> subseq_last;
        multimap<int, size_t> lookup_table;
        for (int num : a) {
            auto iter = lookup_table.lower_bound(num);
            if (iter == lookup_table.begin()) { // need a new subsequence
                subseq_last.emplace_back(num);
                lookup_table.insert(make_pair(num, subseq_last.size() - 1));
            } else {
                --iter;
                int subseq_idx = iter->second;
                lookup_table.erase(iter);
                subseq_last[subseq_idx] = num;
                lookup_table.insert(make_pair(num, subseq_idx));
            }
        }
        return subseq_last.size();
    }
private:

};

int solve() {
    Solution solution;
    // handle IO here
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    cout << solution.sequence_decomposing(a) << endl;
    return 0;
}

} // anonymous namespace

#ifdef OJ_MISC_OFFLINE

#include "epilog.h"

#else

int main() {
    return solve();
}

#endif
