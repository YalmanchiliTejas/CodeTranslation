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
using ll = long long;
int main(){
	int L;
	string s,t;
	cin>>L>>s>>t;
	if(s+t > t+s) swap(s,t);
	ll x = s.size(), y = t.size();
	for(int i=L;i>=0;i--){
		if(x*i<=L && (L-x*i)%y==0){
			int j = (L-x*i)/y;
			string ans;
			rep(k,i) ans += s;
			rep(k,j) ans += t;
			cout<<ans<<endl;
			return 0;
		}
	}
}
