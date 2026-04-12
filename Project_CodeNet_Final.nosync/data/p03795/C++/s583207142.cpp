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
#define WMAX 10000
#define HMAX 10000

//コメントアウトするとdebug()を実行しない
#define DEBUG

using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

typedef pair<int ,int > P;
typedef long long ll;

int A,B,C,N,W,H,ans,dp[HMAX][WMAX];
string S;
static const int dx[8] = {0,1,1,1,0,-1,-1,-1},
					dy[8] = {1,1,0,-1,-1,-1,0,1};

void solve(){
	ans = (N * 800) - ((N/15) * 200);
}

void debug(){

}

void answer(){
	cout << ans << "\n";
}

int main(){
	cin >> N;
	
	solve();
	#ifdef DEBUG
	debug();
	#endif
	answer();

	return 0;
}