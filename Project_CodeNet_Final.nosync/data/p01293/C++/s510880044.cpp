#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <complex>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <functional>
#include <iterator>

using namespace std;

#define dump(n) cout<<"# "<<#n<<'='<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define foreach(i,c) for(auto i=(c).begin();i!=(c).end();++i)
#define all(c) begin(c),end(c)
#define mp make_pair

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int,int> pii;

const int INFTY=1<<29;
const double EPS=1e-9;

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& p){
	return os<<'('<<p.first<<','<<p.second<<')';
}
template<typename T>
ostream& operator<<(ostream& os,const vector<T>& a){
	os<<'[';
	rep(i,a.size()) os<<(i?" ":"")<<a[i];
	return os<<']';
}

int main()
{
	for(char trump;cin>>trump,trump!='#';){
		vector<string> s(4);
		vvi n(4,vi(13));
		rep(i,4) rep(j,13){
			string c; cin>>c;
			switch(c[0]){
			case 'T': n[i][j]=10; break;
			case 'J': n[i][j]=11; break;
			case 'Q': n[i][j]=12; break;
			case 'K': n[i][j]=13; break;
			case 'A': n[i][j]=14; break;
			default:  n[i][j]=c[0]-'0';
			}
			s[i]+=c[1];
		}
		int lead=0;
		int ns=0,ew=0;
		rep(i,13){
			int mx=0;
			rep(j,4){
				if(s[j][i]==trump){
					if(s[mx][i]!=trump || n[j][i]>n[mx][i])
						mx=j;
				}
				else if(s[j][i]==s[lead][i]){
					if(s[mx][i]!=trump && (s[mx][i]!=s[lead][i] || n[j][i]>n[mx][i]))
						mx=j;
				}
			}
			if(mx==0 || mx==2) ns++;
			else               ew++;
			lead=mx;
		}
		if(ns>ew) cout<<"NS "<<ns-6<<endl;
		else      cout<<"EW "<<ew-6<<endl;
	}
}