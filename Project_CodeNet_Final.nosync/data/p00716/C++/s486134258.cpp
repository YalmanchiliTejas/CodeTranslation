#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <complex>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <functional>
#include <iterator>

using namespace std;

#define dump(n) cerr<<"# "<<#n<<"="<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define iter(c) __typeof__((c).begin())
#define foreach(i,c) for(iter(c) i=(c).begin();i!=(c).end();++i)
#define all(c) (c).begin(),(c).end()
#define mp make_pair

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<double,int> pdi;

int main()
{
	int t; cin>>t;
	while(t--){
		int initial,year; cin>>initial>>year;
		int n; cin>>n;
		vector<pdi> simple,compose;
		rep(i,n){
			int type,charge;
			double rate;
			cin>>type>>rate>>charge;
			if(type==0)
				simple.push_back(mp(rate,charge));
			if(type==1)
				compose.push_back(mp(rate,charge));
		}
		int res=0;
		rep(i,simple.size()){
			double rate=simple[i].first;
			int charge=simple[i].second;
			
			int balance=initial,interest=0;
			rep(j,year){
				interest+=balance*rate;
				balance-=charge;
			}
			res=max(res,balance+interest);
		}
		rep(i,compose.size()){
			double rate=compose[i].first;
			int charge=compose[i].second;
			
			int balance=initial;
			rep(j,year){
				balance+=balance*rate;
				balance-=charge;
			}
			res=max(res,balance);
		}
		cout<<res<<endl;
	}
	
	return 0;
}