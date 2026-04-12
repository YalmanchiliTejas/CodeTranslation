#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <complex>
#include <map>
#include <climits>
#include <sstream>
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
typedef pair<pii,string> ttt;
static const int INF=1<<24;
 
template <class T>
void initvv(vector<vector<T> > &v,int a,int b, const T  &t = T()){
    v.assign(a,vector<T>(b,t));
}
 
//v.erase(unique(v.begin(),v.end()),v.end());


int main(){
	int n;
	bool f=false;
	while(cin>>n,n){
		if(f){
			cout<<endl;
			// f=true;
		}
		vector<ttt> v(n);
		rep(i,n){
			string s;
			int a,b,c;
			cin>>s>>a>>b>>c;
			v[i]=mkp(mkp(-3*a-c,i),s);
		}
		sort(ALL(v));
		rep(i,n){
			cout<<v[i].S<<","<<-v[i].F.F<<endl;
		}
		f=true;
	}
}