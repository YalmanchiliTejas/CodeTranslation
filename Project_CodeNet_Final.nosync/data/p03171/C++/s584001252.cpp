


#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <numeric>
#include <deque>
#include <cstring>
#include <iterator>
#include <map>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <complex>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define eb emplace_back
#define el '\n'
typedef  long long  ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vb;


const int mod=1000000007;
//const int mod=998244353;
vvll dp;
vll v;
ll recur(int i, int j ,ll a){
    if(dp[i][j]==-1){
        if(i==j){
            return dp[i][i]=v[i];
        }
        else{
            return dp[i][j]=max(a-recur(i+1,j,a-v[i]),a-recur(i,j-1,a-v[j]));
        }
    }
    return dp[i][j];
}

int main()
{   ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t,n,m,k,q,x,a,b,c,d,y,l,r;
    cin >> n;
    dp.resize(n,vll(n,-1));
    v.resize(n);
    a=0;
    for(int i=0; i<n; i++){
        cin >> v[i];
        a+=v[i];
    }
    cout << 2*recur(0,(int)n-1,a) - a<< el;
    return 0;
}
