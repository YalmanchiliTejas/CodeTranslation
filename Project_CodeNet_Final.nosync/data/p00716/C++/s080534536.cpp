#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <complex>
#include <map>
#include <climits>
using namespace std;

#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define EPS 1e-8
#define F first
#define S second
#define mkp make_pair

static const double PI=6*asin(0.5);
typedef long long ll;
typedef complex<double> CP;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vint;
static const int INF=1<<24;



int main(){
	ll m;
	cin>>m;
	rep(r,m){
		ll res=0;
		ll mo,y,n;
		cin>>mo>>y>>n;
		rep(i,n){
			ll f,c;
			double p;
			cin>>f>>p>>c;
			ll tmp;
			if(f) tmp=mo;
			else tmp=0;
			ll t=mo;
			rep(j,y){
				if(f){
					tmp+=(ll)(tmp*p);
					tmp-=c;
				}
				else{
					tmp+=(ll)(t*p);
					t-=c;
				}
			}
			if(!f) tmp+=t;
			//cout<<tmp<<endl;
			res=max(res,tmp);
		}
		cout<<res<<endl;
		//cout<<endl;
	}
	return 0;
}