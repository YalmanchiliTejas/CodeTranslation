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
#define LLINF 1000000000000000000
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

vector<vector<int>> v(111111);
int zisuu[111111];
bool used[111111];

int main(){
	
	int n;cin >> n;
	REP(i,n-1){
		int a,b;cin >> a >> b;
		a--;b--;
		v[a].PB(b);
		v[b].PB(a);
		zisuu[a]++;
		zisuu[b]++;
	}
	
	queue<int> que;
	REP(i,n){
		if(zisuu[i] == 1)que.push(i);
	}
	
	while(!que.empty()){
		int now = que.front();que.pop();
		//cout << now << " " << used[now] << endl;
		bool flag = !used[now];
		bool madePair = used[now];
		used[now] = true;
		REP(i,v[now].size()){
			zisuu[v[now][i]]--;
			if(flag && !used[v[now][i]]){
				used[v[now][i]] = true;
				madePair = true;
			}
			if(zisuu[v[now][i]] == 1){
				//cout << "   " << v[now][i] << " " << used[v[now][i]] << endl;
				que.push(v[now][i]);
			}
		}
		if(!madePair){
			cout << "First" << endl;
			return 0;
		}
	}
	
	cout << "Second" << endl;
	
	return 0;
}