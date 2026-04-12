#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <map>
#include <algorithm>
#include <limits.h>

#include <sstream>
const int MOD = 1000000007;
using namespace std;

int main()
{
    int n;
    cin >> n;
    auto data = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
		int x=MOD-data[i];
		auto it=upper_bound(ans.begin(),ans.end(),x);
		if (it==ans.end()) ans.push_back(x);
		else *it=x;
    }
    cout << ans.size() << endl;
    return 0;
}
