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
#include <functional>
#include <utility>
#include <algorithm>
#include <numeric>
#include <typeinfo>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <ctime>

using namespace std;

#define dump(n) cout<<"# "<<#n<<"="<<(n)<<endl
#define debug(n) cout<<__FILE__<<","<<__LINE__<<": #"<<#n<<"="<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,n) repi(i,0,n)
#define iter(c) __typeof((c).begin())
#define foreach(i,c) for(iter(c) i=(c).begin();i!=(c).end();i++)
#define allof(c) (c).begin(),(c).end()
#define mp make_pair

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;

void flip(vvi& a,int i,int j)
{
	int di[]={-1,0,0,0,1};
	int dj[]={0,-1,0,1,0};
	rep(k,5){
		int ni=i+di[k],nj=j+dj[k];
		if(0<=ni && ni<10 && 0<=nj && nj<10)
			a[ni][nj]^=1;
	}
}

int main()
{
	int tc; cin>>tc;
	while(tc--){
		vvi a(10,vi(10));
		rep(i,10) rep(j,10)
			cin>>a[i][j];
		rep(k,1<<10){
			vvi b=a;
			vvi res(10,vi(10));
			rep(i,10)
				if(k&(1<<i)){
					flip(b,0,i);
					res[0][i]=1;
				}
			repi(i,1,10)
				rep(j,10)
					if(b[i-1][j]){
						flip(b,i,j);
						res[i][j]=1;
					}
			int count1=0;
			rep(i,10)
				count1+=count(allof(b[i]),1);
			if(count1==0){
				rep(i,10)
					rep(j,10)
						cout<<res[i][j]<<(j==9?'\n':' ');
				break;
			}
		}
	}
	
	return 0;
}