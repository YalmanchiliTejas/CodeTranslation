#include <iostream>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <string.h>

using namespace std;

// #define for(i,a,b) for (int i=(a);i<(b);++i)
typedef long long ll;
typedef pair<ll,ll> P;
#define REP(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back // vectorに要素追加
#define INF (ll)1e18

ll mod = 1e9+7;
  
// 検索タグ
int main() {
	// 入力
	string S;cin>>S;
    
	// 解法
	bool ans = true;
	// printf("%s\n", S.c_str());
	if (S[0]==S[1] & S[1]==S[2]) ans = false;

	//出力
	if (ans) printf("Yes\n");
	else printf("No\n");
}
