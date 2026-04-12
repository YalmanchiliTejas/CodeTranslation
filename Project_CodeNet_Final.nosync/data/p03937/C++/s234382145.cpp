#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;




int main(){
	int H,W; cin >> H >> W;
	vector<vector<char>> a(H,vector<char>(W));
	int cnt = 0;;
	rep(i,H)rep(j,W){
		cin >> a[i][j];
		if(a[i][j] == '#') cnt++;
	}
	cout << (cnt == H+W-1 ? "Possible" : "Impossible") << endl;
}

