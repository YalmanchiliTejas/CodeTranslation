
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
ll ans=0;
ll dp[10001][101];
int d;
void solve(string &a , int p){
    int no=a.back()-'0';
    a.pop_back();
    int len=(int)a.length();
    if(a.length()==0){
        for(int i=0 ;i<=no; i++)
            if(i%d==p)
                ans++;
        return;
    }
    for(int i=no-1; i>=0; i--){
        ans+=dp[len][((p+d-i)%d+d)%d];
        ans%=mod;
    }
    if(a.length()>0)
        solve(a,((p+d-no)%d+d)%d);
}



int main()
{   ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t,n,m,k,q,x,a,b,c,y,l,r;
    string s;
    cin >> s;
    reverse(all(s));
    n=(int)s.length();
    cin >> d;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0; i<10000; i++){
        for(int j=0; j<101; j++){
            if(dp[i][j]!=0){
                for(int k=0; k<=9; k++){
                    dp[i+1][(j+k)%d]+=dp[i][j];
                    dp[i+1][(j+k)%d]%=mod;
                }
            }
        }
    }
    solve(s,0);
    cout << (ans-1+mod)%mod << el;
    
    return 0;
}
