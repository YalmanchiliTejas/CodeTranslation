#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define MOD 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
	int a,b,c;
	cin >> a >> b >> c;
	int x,y;
	cin >> x >> y;
	ll counta = x, countb = y, countc = 0;
	ll mini = a*counta + b*countb;
	while(1) {
		if(counta > 0) counta--;
		if(countb > 0) countb--;
		countc += 2;
		chmin(mini, a*counta + b*countb + c*countc);
		if(counta == 0 && countb == 0) break;
	}
	cout << mini << endl;
	

  return 0;
}
