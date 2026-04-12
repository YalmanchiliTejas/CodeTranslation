#include <bits/stdc++.h>
using namespace std;
// 287644PV
#define FIXED_FLOAT(x) std::fixed <<std::setprecision(10)<<(x)

long long game2(int s, int e,bool t ,vector<int>&a, vector<vector<vector<long long>>> &memo){
    if (s == e) return t ? a[s] : - a[s];
    else if(memo[s][e][t] != 1e18)
        return memo[s][e][t];
    else if(t)
    {
        memo[s][e][t] = max(a[s] + game2(s+1,e,!t,a,memo),a[e] + game2(s,e-1,!t,a,memo));
        return memo[s][e][t];
    } else
    {
        memo[s][e][t] = min(-a[s] + game2(s+1,e,!t,a,memo),-a[e] + game2(s,e-1,!t,a,memo));
        return memo[s][e][t];
    }
}



int mod = 1000000000+7;

long long game(long long curr, long long x, long long y, vector<int> &a, bool t, int beg, int end)
{
    if(beg == end)
            return a[beg];
    else if(t) {
        curr += max(a[beg] + game(curr,x, y, a, false, beg + 1, end), a[end] + game(curr,x, y, a, false, beg, end - 1));
        return curr;
    }
    else {
         curr -= max(a[beg] + game(curr,x, y, a, true, beg + 1, end), a[end] + game(curr,x, y, a, true, beg, end - 1));
         return curr;
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<vector<long long>>> memo(n,vector<vector<long long>>(n,vector<long long>(2,1e18)));
    cout << game2(0,a.size()-1,true,a,memo);

}