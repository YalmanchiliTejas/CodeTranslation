#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
typedef long long ll;
int N;
ll a[50];
int main(){
	cin>>N;
	rep(i,N) cin>>a[i];
	ll ans = 0;
	while(true){
		bool update = 0;
		rep(i,N) if(a[i]>=N){
			ll q = a[i]/N;
			a[i] -= q*N;
			rep(j,N) if(i!=j) a[j]+=q;
			ans += q;
			update = 1;
		}
		if(!update) break;
	}
	cout<<ans<<endl;
}
