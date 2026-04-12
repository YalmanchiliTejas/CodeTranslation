#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

int n, a, d, m, K, x[200000], y[200000], z[200000];

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> a >> d >> m;
	rep(i, m){
		cin >> x[i] >> y[i] >> z[i];
		y[i]--;
	}
	cin >> K; K--;
	
	for(int i = m - 1; i >= 0; i--) if(x[i] == 0){
		if(y[i] <= K && K < z[i]) K = z[i] - 1 - K + y[i];
	}
	int cur = a + K * d;
	rep(i, m){
		if(x[i] == 0 && y[i] <= K && K < z[i]) K = z[i] - 1 - K + y[i];
		if(x[i] == 1 && y[i] <= K && K < z[i]) cur++;
		if(x[i] == 2 && y[i] <= K && K < z[i]) cur /= 2;
	}
	cout << cur << endl;
	
	return 0;
}