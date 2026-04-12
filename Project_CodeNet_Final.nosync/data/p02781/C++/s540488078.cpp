#pragma region includes, macros
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <map>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>

using namespace std;
 
typedef int64_t i64;
typedef pair<i64, i64> P;

template<class T>
const T INF = numeric_limits<T>::max();
template<class T>
const T SINF = numeric_limits<T>::max() / 10;
static const i64 MOD = 1000000007;

//int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
//int dx[5] = {-1,0,0,0,1}, dy[5] = {0,-1,0,1,0};
//int dx[8] = {-1,0,1,1,1,0,-1,-1}, dy[8] = {1,1,1,0,-1,-1,-1,0};
//int dx[9] = {-1,0,1,1,1,0,-1,-1,0}, dy[9] = {1,1,1,0,-1,-1,-1,0,0};

struct edge {
	i64 from, to, cost;
	edge(i64 to, i64 cost) : from(-1), to(to), cost(cost) {}
	edge(i64 src, i64 to, i64 cost) : from(src), to(to), cost(cost) {}
};

// 多重vectorを可変引数テンプレートで http://beet-aizu.hatenablog.com/entry/2018/04/08/145516
template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
	return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
	for(auto &e:t) fill_v(e,v);
}
//

#pragma endregion

int main(){
    string s;
    cin >> s;
    i64 n = s.length();
    i64 k;
    cin >> k;
    vector<vector<vector<i64>>> dp(n + 1, vector<vector<i64>>(4, vector<i64>(2, 0)));
    dp[0][1][0] = 1;
    dp[0][1][1] = s[0] - '1';
    for(i64 i = 1; i < n; ++i){
        if(s[i] == '0'){
            for(i64 j = 1; j <= 3; ++j){
                dp[i][j][0] = dp[i - 1][j][0];
            }
            for(i64 j = 1; j <= 3; ++j){
                if(j == 1) dp[i][j][1] = dp[i - 1][j - 1][1] * 9 + dp[i - 1][j][1] + 9;
                else dp[i][j][1] = dp[i - 1][j - 1][1] * 9 + dp[i - 1][j][1];
            }
        }else{
            for(i64 j = 1; j <= 3; ++j){
                dp[i][j][0] = dp[i - 1][j - 1][0];
            }
            for(i64 j = 1; j <= 3; ++j){
                if(j == 1) dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j - 1][1] * 9 + dp[i - 1][j][0] + dp[i - 1][j - 1][0] * (s[i] - '1') + 9;
                else dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j - 1][1] * 9 + dp[i - 1][j][0] + dp[i - 1][j - 1][0] * (s[i] - '1');
            }
        }
    }
    cout << dp[n - 1][k][1] + dp[n - 1][k][0] << endl;
}