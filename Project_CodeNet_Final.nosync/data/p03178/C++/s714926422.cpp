#pragma GCC target("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#define int ll
#define f			first
#define sz(a)       ((int)(a).size())
#define s			second
#define all(v)		v.begin(),v.end()
#define pii 		pair<int,int>
#define vpii 		vector<pii>
#define eb			emplace_back
#define pb			push_back
#define fo(i,n)		for(int i=0;i<n;i++)
#define Fo(i,k,n)	for(int i=k;i<n;i++)
#define vi			vector<int>

using namespace std;
using ll  = long long;
using lld = long double;

const int oo = 0x3f3f3f3f;
const ll MOD = 1000000007;

const int N = 1e5 + 10;
string ar;
int d;
int dp[N][102][2];

int fun(int pos , int tyt , int sum){
    if(pos == ar.size())
        return sum == 0;
    auto & res = dp[pos][sum][tyt];
    if(res != -1)
        return res;
    int lim = tyt ? ar[pos] - '0' : 9;
    int ans = 0;
    for(int i = 0 ; i <= lim ; i++)
        ans = (ans % MOD + fun(pos + 1 , tyt & (i == lim) , (sum + i) % d) % MOD) % MOD; 
    return res = ans;
}

signed main(){

#ifndef ONLINE_JUDGE
#endif
	ios_base::sync_with_stdio(0);cin.tie(0);
    
    memset(dp , -1 , sizeof dp);
    cin >> ar;
    cin >> d;
    cout << (fun(0 , 1 , 0) - 1 + MOD) % MOD << '\n';;
    

    return 0;

}

