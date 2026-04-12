#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>
#include<bitset>

using namespace std;

#define ll long long int

ll const MOD = 1000000007;
ll const INF = (long long int)1 << 61;

ll solve(vector<ll> &a,vector<ll> &b,ll lev,ll pos){
    if(lev == 0){
        return 1;
    }
    if(pos == 1){
        return 0;
    }
    if(pos == a[lev]){
        return b[lev];
    }
    if(pos == a[lev-1]+2){
        return b[lev-1]+1;
    }
    if(pos < a[lev-1]+2){
        return solve(a,b,lev-1,pos-1);
    }
    if(pos > a[lev-1]+2){
        return b[lev-1] + 1 +  solve(a,b,lev-1,pos-a[lev-1]-2);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n,x;
    cin >> n >> x;

    vector<ll> total(n+1,0);
    vector<ll> p(n+1,0);
    p[0] = 1;
    total[0] = 1;
    for(int i = 1; i <= n; i++){
        total[i] = total[i-1]*2+3;
        p[i] = p[i-1]*2+1;
    }

    cout << solve(total,p,n,x) << endl;

    
    return 0;
}