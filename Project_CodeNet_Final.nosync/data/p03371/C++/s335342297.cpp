#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7;
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

ll A,B,C;
ll X,Y;
ll ans=mod;

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>A>>B>>C>>X>>Y;

rep(x,X+1){
	ll costA=A*x+2*C*(X-x);
	ll costB;
	if(X-x>=Y){
		costB=0;
	}else{
		costB=(Y-(X-x))*min(B,2*C);
	}
	ans=min(ans,costA+costB);
}

cout<<ans<<endl;

}
	
