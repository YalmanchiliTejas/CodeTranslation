#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <algorithm>
#define NMAX 10
#define MMAX 29
//コメントアウトするとdebug()を実行しない
#define DEBUG
 
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
	std::fill( (T*)array, (T*)(array+N), val );
}
 
typedef pair<int ,int > P;
vector<int > land[NMAX];
vector<int > rest;
int A[MMAX],B[MMAX],C,N,M,W,H,ans = 0,dp[NMAX][NMAX] = {},flag[NMAX];
string S;
static const int dx[8] = {0,1,1,1,0,-1,-1,-1},
dy[8] = {1,1,0,-1,-1,-1,0,1};
void dfs(int a){
	if(rest.empty()){
		ans++;
	}
	// printf("%d :",a);
	for (int i = 0; i < land[a].size(); ++i)
	{
		// printf("%d\n",land[a][i]);
		if(find(rest.begin(), rest.end(),land[a][i]) != rest.end()){
			rest.erase(find(rest.begin(), rest.end(),land[a][i]));
			// printf("%d::::\n",land[a][i]);
			dfs(land[a][i]);
			rest.push_back(land[a][i]);
		}
	}
 
}
 
void solve(){
	
}
 
void debug(){
 
}
 
void answer(){
	cout << ans << "\n";
}
 
int main(){
	ios::sync_with_stdio(false);
	Fill(flag,1);
	cin >> N >> M;
	for (int i = 1; i < N; ++i)
	{
		rest.push_back(i+1);
	}
	for (int i = 0; i < M; ++i)
	{
		scanf("%d%d",&A[i],&B[i]);
		land[A[i]].push_back(B[i]);
		land[B[i]].push_back(A[i]);
	}
	// for (int i = 0; i < N; ++i)
	// {
	// 	for (int j = 0; j < land[i].size(); ++j)
	// 	{
	// 		printf("%d ",land[i+1][j]);
	// 	}
	// 	printf("\n");
	// }
	solve();
	#ifdef DEBUG
	debug();
	#endif
	dfs(1);
	answer();
 
	return 0;
}