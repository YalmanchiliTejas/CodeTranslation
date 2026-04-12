#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>

using namespace std;
using pii=pair<int,int>;
using ll=long long;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vector<int> dp;
    for(int aa : a){
        auto it=lower_bound(dp.rbegin(),dp.rend(),aa);
        if(it==dp.rbegin()) dp.push_back(aa);
        else{
            it--;
            *it=aa;
        }
    }
    cout<<dp.size();

    return 0;
}
