#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;
vector<vector<int>> v(9,vector<int>(9,-1));//-1は辺がない
int n;
queue<P> que;
int ans = 0;
void search(){
	while(que.size()!= 0){
		ll x = que.front().fs;
		ll used = que.front().sc;
		que.pop();
		used |= (1 << (x -1));
		for(int i = 1; i <= n; i++) {
			if (v[x][i] == 1 && !(1 & used >> (i- 1))){
				que.push(mp(i,used));
			}
		}
		if (used == (1<< n) - 1){
			ans += 1;
		}
	}
}
int main(){
	int m,a,b;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a][b] = 1;
		v[b][a] = 1;
	}
	que.push(mp(1,0));
	search();
	cout << ans <<endl;
	
	return 0;
}