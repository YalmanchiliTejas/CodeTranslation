#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
 
using namespace std;
 
#define pb(n)	push_back(n)
#define mp(n,m) make_pair(n,m)
#define fi 	first
#define se 	second
#define all(r) (r).begin(),(r).end()

#define rep(i,n) for(int i=0; i<(n); i++)
#define repc(i,a,b) for(int i=(a); i<(b); i++)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
const int IMAX=((1<<30)-1)*2+1;
const double EPS=1e-10;
//int mod=1000000007


int main(){
	int n;
	int a,b,c;
	string s;
	bool f=false;
	while(cin>>n && n>0){
		vector<pair<pii,string> >v(n);
		rep(i,n){
			cin>>s>>a>>b>>c;
			v[i].fi.fi=a*3+c;
			v[i].fi.se=i*(-1);
			v[i].se=s;
		}
		sort(all(v));
		reverse(all(v));
		if(f)cout<<endl;
		f=true;
		rep(i,n){
			cout<<v[i].se<<","<<v[i].fi.fi<<endl;
		}
	}
}