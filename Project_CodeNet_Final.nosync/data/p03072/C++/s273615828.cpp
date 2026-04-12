#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<string>
#include<bitset>
#include <sstream>
#include<queue>
#include<set>
#define rep(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,ll>P;

const ll mod = 1e9+7;
const ll INF = ll(1e18)+1;
const ll MAXN = 1e6;

int main()
{
    int n;
    cin>>n;
    int h[n];
    rep(i,n)cin>>h[i];
    int ans=0;
    rep(i,n)
    {
        bool flag=true;
        rep(j,i)
        {
            if(h[i]<h[j])flag=false;
        }
        if(flag)ans++;
        
    }
    cout<<ans;

}