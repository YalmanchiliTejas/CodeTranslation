#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define It iterator
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=100003;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}


int n,m,eLast,bLast;
string s;

int main(){
    //freopen("test.in","r",stdin);
    cin>>n>>m;
    rep(i,0,n) {
        cin>>s;
        int b=-1,e=-1;
        rep(i,0,m) if(s[i]=='#') {b=i; break;}
        if(b<0) goto quickExit;
        rep(i,b,m) if(s[i]=='.') {e=i-1; break;}
        if(e<0) e=m-1;
        rep(i,e+1,m) if(s[i]=='#') goto quickExit;

        if(b!=eLast) goto quickExit;
        bLast=b; eLast=e;
    }

    cout<<"Possible";
    return 0;
quickExit:
    cout<<"Impossible";
    return 0;
}
