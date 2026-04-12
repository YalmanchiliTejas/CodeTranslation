#pragma GCC optimize ("O3")
#define _CRT_DISABLE_PERFCRIT_LOCKS
#include <bits/stdc++.h>

using namespace std;
#define BOOST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define fileIn freopen("1.txt", "r", stdin)
#define fileOut freopen("output.txt", "w", stdout)
#define dbg(n) cout << n <<"\n"
#define dbg2(n) cout << n <<" "
#define all(a) a.begin(), a.end()
#define cinArr(arr) for(auto &v : arr) cin>>v
#define coutArr(arr) for(auto &v : arr) cout<<v<<" "
#define FOR(i, a, b) for(int i = a; i < b; i++)
typedef int64_t ll;
typedef uint64_t ull;
typedef vector<int> vi;
typedef vector<vi > vii;


int main()
{
    BOOST;
    int n;
    cin>>n;
    int ans = 1, mx;
    cin>>mx;
    FOR(i, 1, n){
        int tmp;
        cin>>tmp;
        if(tmp >= mx) mx = tmp, ans++;
    }
    cout<<ans;
    return 0;
}



















