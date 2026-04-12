#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=2e5;
int N;
typedef pair<ll,ll> P;
P bal[MAX_N*2];
int main(){
	cin>>N;
	ll ans=1e18;
	ll ma,mi;
	{
		set<ll> sr,sb;
		REP(i,N){
			ll x,y;
			cin>>x>>y;
			if (x>y){
				swap(x,y);
			}
			sr.insert(x);
			sb.insert(y);
			bal[i*2]=P(x,y);
			bal[i*2+1]=P(y,0);
		}
		ll rmi,rma,bmi,bma;
		auto ite=sr.begin();
		rmi=*ite;
		ite=sr.end();
		ite--;
		rma=*ite;
		ite=sb.begin();
		bmi=*ite;
		ite=sb.end();
		ite--;
		bma=*ite;
		ans=min(ans,(rma-rmi)*(bma-bmi));
		mi=rmi;
		ma=bma;
	}
	sort(bal,bal+N*2);
	{
		priority_queue<ll> pque;
		REP(i,N*2){
			if (bal[i].second!=0){
				pque.push(bal[i].first);
			}
		}
		REP(i,N*2){
			ans=min(ans,(ma-mi)*(pque.top()-bal[i].first));
			if (bal[i].second!=0){
				pque.push(bal[i].second);
			}else{
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}