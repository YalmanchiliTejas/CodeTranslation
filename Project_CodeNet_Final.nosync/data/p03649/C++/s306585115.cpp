#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
const int mod=1e9+7;

int main(){
    int n;cin>>n;
    ll a[n];rep(i,n)cin>>a[i];
    ll ans=0;
    bool flag=1;
    while(flag){
        flag=0;
        rep(i,n){
            if(a[i]>=n){
                ll p=a[i]/n;
                ans+=p;          
                a[i]-=p*n;
                flag=1;
                rep(j,n){
                    if(j!=i)a[j]+=p;
                }
            }
        }
        if(!flag)break;
    }
    cout<<ans<<endl;
}