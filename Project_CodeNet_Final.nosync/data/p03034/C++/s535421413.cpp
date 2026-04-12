
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define PF push_front
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int,int>
#define pll pair<LL,LL>

const double pi = 3.14159265358979323846264;
const int mod=1000000007;

int main(){
	 //cin.tie(0);
	//ios::sync_with_stdio(false);
	//std::cout << std::fixed;
	//std::cout << std::setprecision(12);
	//std::cout << std::defaultfloat;
	int n;
	cin>>n;
	vector<LL> s(n);
	LL ans=0;
	FOR(i,0,n)cin>>s[i];
	FOR(i,1,n/2){
		LL t=0;
		int l=i,r=n-1-i;
		set<LL> st;
		FOR(j,0,n){
			if(l>=n-1||r<=0)break;
			if(st.find(l)!=st.end()||st.find(r)!=st.end()||l==r)break;
			if((n-1)%i==0&&l>=r)break;
			if(r-i<=0)break;
			st.insert(l);
			st.insert(r);
			t+=s[l]+s[r];
			ans=max(t,ans);
			l+=i;
			r-=i;
		}
	}

	cout<<ans<<endl;
	return 0;
}
