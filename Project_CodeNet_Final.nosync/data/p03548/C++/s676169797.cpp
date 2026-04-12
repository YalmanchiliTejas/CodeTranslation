#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>

#define x first
#define y second
#define mp make_pair
#define up_b upper_bound
#define low_b lower_bound
#define pii pair<int,int>
#define bit __builtin_popcount
#define all(x) x.begin(),x.end()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF=1e18;
const ld EPS=1e-9;
const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll x,y,z;
	cin>>x>>y>>z;
	for(ll i=N;i>=0;i--){
		if(i*y+(i+1)*z<=x){
			cout<<i;
			return 0;
		}
	}
	return 0;
}