#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <deque>
#define NMAX 9
#define MMAX 30

//コメントアウトするとdebug()を実行しない
#define DEBUG

using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

typedef pair<int ,int > P;
typedef long long ll;

int A[MMAX],B[MMAX];
int C,N,M,W,H,ans = 0;
string S;
vector<int > con[NMAX],rest;
static const int dx[8] = {0,1,1,1,0,-1,-1,-1},
					dy[8] = {1,1,0,-1,-1,-1,0,1};

void dfs(int a){
	if(rest.empty()){
		ans++;
	}
	for (int i = 0; i < con[a].size(); ++i)
	{
		if(find(rest.begin(), rest.end(),con[a][i]) != rest.end()){
			rest.erase(find(rest.begin(), rest.end(),con[a][i]));
			dfs(con[a][i]);
			rest.push_back(con[a][i]);
		}
	}
}

void solve(){
	for (int i = 1; i < N; ++i)
	{
		rest.push_back(i+1);
	}
	dfs(1);
}

void debug(){

}

void answer(){
	cout << ans << "\n";
}

int main(){
	
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> A[i] >> B[i];
		con[A[i]].push_back(B[i]);
		con[B[i]].push_back(A[i]);
	}

	solve();
	#ifdef DEBUG
	debug();
	#endif
	answer();

	return 0;
}