#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional> //operator[]
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

signed main(){
    int n,k; cin >> n >> k;
    ll ans=0;
    for(int i=k+1;i<=n;i++){
        int x=n/i;
        int y=n%i;
        //n=i*x+y
        if(y<k) ans+=x*(i-k);
        else{
            ans+=(x+1)*(y-k+1);
            ans+=x*(i-y-1);
        }
        //cout << ans << endl;
    }
    if(k==0) ans-=n;
    cout  << ans << endl;
}

