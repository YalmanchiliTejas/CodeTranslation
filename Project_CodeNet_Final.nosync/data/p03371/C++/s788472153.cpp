#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

int main(){
    ll A,B,C,X,Y;cin>>A>>B>>C>>X>>Y;
    ll ans=1e9;
    for(int i=0;i<=100000;++i){
        ll tmp=A*i;
        int j=Y;
        if(X-i>0){
            tmp+=2*C*(X-i);
            j-=X-i;
        }
        tmp+=min(B*max(0,j),2*C*max(0,j));
        ans=min(ans,tmp);
    }
    cout<<ans<<endl;
}
