#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG_MODE
	#define DBG(n) n;
#else
	#define DBG(n) ;
#endif
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

ll dp[1<<18];
int d[111];
int inD[20];

int main(){

	REP(i,111)d[i] = -1;
	REP(i,(1<<18))dp[i] = INF;

	int N,M,K;cin >> N >> M >> K;
	REP(i,M){
		cin >>inD[i];inD[i]--;
		d[inD[i]] = i;
	}

	vector<vector<int>> v;
	REP(i,N){
		vector<int> tmp(K);
		REP(j,K){
			cin >> tmp[j];
			tmp[j]--;
		}
		v.PB(tmp);
	}

	dp[(1<<M)-1] = 0;
	queue<int> q;
	q.push((1<<M)-1);

	while(!q.empty()){
		int now = q.front();q.pop();
		//cout << bitset<10>(now) << endl;
		REP(i,K){
			int tmp = 0;
			REP(j,M){
				if(now & (1<<j)){
					int hoge = d[v[inD[j]][i]];
			//		cout << "    " << inD[j] << " " << v[inD[j]][i] << " " << hoge << endl;
					if(hoge != -1)tmp |= (1 << hoge);
				}
			}
			//cout << " " << bitset<10>(tmp) << endl;
			if(dp[tmp] > dp[now] + 1){
				dp[tmp] = dp[now] + 1;
				q.push(tmp);
			}
		}
	}

	cout << dp[0] << endl;


	return 0;
}

