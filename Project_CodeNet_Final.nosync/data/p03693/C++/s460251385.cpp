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
#include <cmath>
#define WMAX 10000
#define HMAX 10000

//コメントアウトするとdebug()を実行しない
#define DEBUG

using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

typedef long long ll;
typedef pair<int ,int > P;

struct edge{
  int to,cost;
};

int A,B,C,N,W,H,ans,dp[HMAX][WMAX];
string S;
static const int dx[8] = {0,1,1,1,0,-1,-1,-1},
					dy[8] = {1,1,0,-1,-1,-1,0,1};

void solve(){
	N = B*10 + C;
	if(N % 4)
		cout << "NO\n";
	else
		cout << "YES\n";
}

void debug(){

}

void answer(){
	cout << ans << "\n";
}

int main(){
	cin >> A >> B >> C;
	solve();
	#ifdef DEBUG
	debug();
	#endif
	// answer();

	return 0;
}