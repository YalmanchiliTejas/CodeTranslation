#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
#define sort(v) sort(v.begin(),v.end())
#define reverse(v) reverse(v.begin(),v.end())
#define count(v,x) count(v.begin(),v.end(),x)
#define find(v,x) find(v.begin(),v.end(),x)


priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int a,b,c,x,y;

void solve(){
    cin >> a >> b >> c >> x >> y;
    llint ans=inf;
    int z=max(x,y);
    for(int i=0;i<=z;i++){
        llint tmp=i*2*c+max((x-i),0)*a+max(y-i,0)*b;
        ans=min(ans,tmp);
    }
    cout << ans << endl;

}

int main(){
    solve();
    return 0;
}



