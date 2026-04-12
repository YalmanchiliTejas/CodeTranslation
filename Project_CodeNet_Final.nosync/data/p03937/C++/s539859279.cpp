#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

#define sz size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define clr(a, b) memset((a), (b) ,sizeof(a))
#define ctos(c) string(1,c)
#define print(x) cout<<#x<<" = "<<x<<endl;

#define MOD 1000000007

ll h ,w;
ll d[10][10];
ll flag;

void f(ll dd[16]){
	ll d1[10][10];
	clr(d1,0);
	ll x = 0;
	ll y = 0;
	rep(i,0,16){
		d1[y][x] = 1;
		if(x==w-1&&y==h-1)break;
		if(dd[i]==1){
			x++;
		}
		else{
			y++;
		}
		if(x>=w)return;
		if(y>=h)return;
	}
	ll flag1 = 1;
	rep(y,0,h){
		rep(x,0,w){
			if(d[y][x]!=d1[y][x])flag1 = 0;
		}
	}
	if(flag1 == 1)flag = 1;
}

int main() {
	flag = 0;
	cin>>h>>w;
	vector<string> vs;
	clr(d,0);
	rep(i,0,h){
		string s;
		cin>>s;
		rep(j,0,s.sz){
			if(s[j]=='#'){
				d[i][j] = 1;
			}
		}
	}
	rep(i,0,1<<16){
		ll dd[16];
		clr(dd,0);
		rep(j,0,16){
			if((i>>j)&1){
				dd[j]=1;
			}
		}
		f(dd);
	}
	if(flag == 1){
		cout << "Possible" << endl;
	}
	else{
		cout << "Impossible" << endl;
	}
	return 0;
}