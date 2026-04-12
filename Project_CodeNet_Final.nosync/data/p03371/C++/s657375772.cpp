#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    if(a+b<=2*c){
        cout<<a*x+b*y<<endl;
    }else{
        int ans = inf;
        //cout<<2*max(x,y)<<endl;
        for(int i=0;i<=2*max(x,y);i++){
            if(i%2!=0) continue;
            //if(i==866) cout<<"check"<<i<<endl;
            int now=0;
            now+=i*c;
            int xx=x-i/2;
            int yy=y-i/2;
            now+=(a*max(xx,0)+b*max(yy,0));
            ans = min(ans,now);
        }
        cout<<ans<<endl;
    }
    return 0;
}