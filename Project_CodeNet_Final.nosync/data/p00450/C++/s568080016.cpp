#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <valarray>
#include <vector>

#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(auto it=(X).begin();it!=(X).end();it++)
#define ite iterator
#define mp make_pair
#define mt make_tuple
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define pb push_back
#define sec second
#define sz(x) ((int)(x).size())

using namespace std;

struct timer{
	time_t start;
	timer(){start=clock();}
	~timer(){cerr<<1.*(clock()-start)/CLOCKS_PER_SEC<<" secs"<<endl;}
};

typedef istringstream iss;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef stringstream sst;
typedef vector<ll> vi;

int n;
pi s[100010];

int main2(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	if(n==0)return 1;
	int end=0;
	rep(i,n){
		int c;
		cin>>c;
		if(i%2==0){
			if(end==0){
				s[end++]=mp(c,1);
			}else{
				if(s[end-1].fir==c)s[end-1].sec++;
				else s[end++]=mp(c,1);
			}
		}
		if(i%2==1){
			if(s[end-1].fir==c)s[end-1].sec++;
			else{
				s[end-1].fir^=1;
				s[end-1].sec++;
				if(end>=2){
					s[end-2].sec+=s[end-1].sec;
					end--;
				}
			}
		}
	}
	int ans=0;
	rep(i,end)if(s[i].fir==0)ans+=s[i].sec;
	cout<<ans<<endl;
	return 0;
}

int main(){
	while(!main2());
}