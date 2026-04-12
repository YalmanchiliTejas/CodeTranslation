#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <iterator>
#include <functional>
#include <utility>
#include <algorithm>
#include <numeric>
#include <typeinfo>

using namespace std;

#define dump(n) cerr<<"# "<<#n<<"="<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,n) repi(i,0,n)
#define iter(c) __typeof((c).begin())
#define foreach(i,c) for(iter(c) i=(c).begin();i!=(c).end();++i)
#define allof(c) (c).begin(),(c).end()
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

int main()
{
	for(vi ns(6);;){
		rep(i,6) cin>>ns[i];
		if(count(allof(ns),0)==6) break;
		
		vi a(3);
		rep(i,6) a[i%3]+=ns[i];
		
		vi c(4);
		c[3]=*min_element(allof(a));
		rep(i,3){
			c[i]=(a[i]-c[3])/3;
			a[i]-=c[i]*3+c[3];
		}
		
		//cout<<"a:"; rep(i,3) cout<<" "<<a[i]; cout<<endl;
		//cout<<"c:"; rep(i,4) cout<<" "<<c[i]; cout<<endl;
		
		int res=accumulate(allof(c),0);
		if(count(allof(a),2)==2 && c[3]>0)
			res++;
		cout<<res<<endl;
	}
	
	return 0;
}