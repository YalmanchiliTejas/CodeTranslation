#include<iostream>
#include<cstdio>
#include<string>
#include<math.h>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<map>
#include<numeric>
#include<stack>
#include<queue>
#include<functional>
#include<cassert>
#include<set>
#include<numeric>
#define rep(a,b) for(ll a=0;a<b;++a)
#define REP(a,b,c,d) for(ll a=b;a<c;a+=d)
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define mod 1000000007
using namespace std;
using ll = long long;
using p_ll = pair<ll, ll>;
int main() {
	int N, num = 0;	cin >> N;
	vector<int> h(N);
	rep(i, N)cin >> h[i];
	rep(i, N) {
		bool ok = true;
		rep(j,i) {
			if (h[j] > h[i]) {
				ok = false;
				break;
			}
		}
		if (ok)++num;
	}
	cout << num << endl;
	cin >> N;
}