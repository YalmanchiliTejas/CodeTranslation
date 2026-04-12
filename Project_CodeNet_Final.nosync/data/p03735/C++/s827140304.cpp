#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mt make_tuple
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef tuple<int,int,int> tp;
typedef vector<tp> vt;
typedef vector<vd> vvd;
typedef pair<int,pii> pip;
typedef vector<pip>vip;
const double PI=acos(-1);
const double EPS=1e-7;
const int inf=1e8;
const ll INF=2e18;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
typedef ll SegT;
class SegTree{
	private:
		vector<SegT>val;
		ll n,defvalue;
		SegT combine(SegT a,SegT b){return defvalue==INF?min(a,b):max(a,b);}
	public:
		SegTree(ll size,ll a){
			defvalue=a;
			n=1;
			while(n<size)n<<=1;
			val=vector<SegT>(2*n,defvalue);
		}
		SegTree(const vector<SegT> &in,ll a){
			n=1;
			defvalue=a;
			while(n<in.size())n<<=1;
			val=vector<SegT>(2*n,defvalue);
			for(ll i=n-1+in.size()-1;i>=0;i--){
				if(n-1<=i)val[i]=in[i-(n-1)];
				else val[i]=combine(val[i*2+1],val[i*2+2]);
			}
		}
		void update(ll i,SegT a){
			i+=n-1;
			val[i]=a;
			while(i>0){
				i=(i-1)/2;
				val[i]=combine(val[i*2+1],val[i*2+2]);
			}
		}
		SegT query(ll a,ll b,ll k=0,ll l=0,ll r=-1){//[a,b)
			if(r==-1)r=n;
			if(r<=a||b<=l)return defvalue;
			if(a<=l&&r<=b)return val[k];
			else return combine(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
		}
		void tmp(){
			rep(i,val.size())cout<<" "<<val[i];cout<<endl;
		}
};
int main(){
	ll out=INF;
	int n;
	vp in;
	cin>>n;
	in=vp(n);
	
	rep(i,n){
		ll a,b;
		cin>>a>>b;
		if(a<b)swap(a,b);
		in[i]=pii(a,b);
	}
	sort(all(in));
	vi A(n),B(n);
	rep(i,n){
		A[i]=in[i].first;
		B[i]=in[i].second;
	}
	SegTree st1(A,INF),st2(A,-INF),st3(B,INF),st4(B,-INF);
	out=(st1.query(0,n+1)-st2.query(0,n+1))*(st3.query(0,n+1)-st4.query(0,n+1));
	for(int i=n-1;i>=0;i--){
		st1.update(i,in[i].second);
		st2.update(i,in[i].second);
		st3.update(i,in[i].first);
		st4.update(i,in[i].first);
		
		out=min(out,(st1.query(0,n+1)-st2.query(0,n+1))*(st3.query(0,n+1)-st4.query(0,n+1)));
	}
	cout<<out<<endl;
}









