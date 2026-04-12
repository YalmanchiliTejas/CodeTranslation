#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define pb push_back
const int maxn = 10000;
const int INF32 = 1'050'000'000;
const long long INF64 = 4'000'000'000'000'000'000;
const int MOD7 = 1'000'000'007;
const int MOD9 = 1'000'000'009;

void ERROR(int num) { printf("ERROR%d!\n",num); }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[8]={-1,0,1,0,1,1,-1,-1};
int dy[8]={0,-1,0,1,1,-1,1,-1};

int N, M;
vector<vector<int>> G;

int main(){
	cin >> N >> M;
	G.resize(N);
	rep(i,N) G[i].resize(M);
	rep(i,M){
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a][b] = G[b][a] = 1;
	}

	vector<int> array(N);
	rep(i,N) array[i] = i;

	int cnt = 0;
	do{
		if(array[0]!=0) break;
		int ok = 1;
		for(int i = 0; i+1<N; i++){
			int from = array[i];
			int to = array[i+1];
			if(G[from][to]==0) ok = 0;
		}
		if(ok) cnt++;
	}while(next_permutation(array.begin(), array.end()));

	cout << cnt << endl;
}