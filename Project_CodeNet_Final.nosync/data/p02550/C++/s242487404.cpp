//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/abc179/tasks/abc179_e

//ポイント：
//制約が10^10となっているときに使えそうなアルゴリズム
//二部探索
//ダブリング
//ループ構造
 
//今回はmodのループする性質を用いる

//ループする場合
//スタート地点からある距離まで進んだ地点がループ開始地点
//スタート地点がループ開始地点
//の場合がある

//また、ループの時はグラフに起こしてみると分かりやすくなる場合がある
 
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <map> 
#include <unordered_map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N,X,M;

LL ans = 0;

void solve(){
    //i回の操作までの累積和をaccum[i]とおく
    vector<LL> accum(M+1,0);
    //ループ一回あたりの操作回数
    LL operation_per_loop = 0;
    //ループ一回あたりの和
    LL sum_per_loop = 0;
    //ループ開始地点
    LL loop_start_Ai = 0;
    //最初の状態から操作を何回繰り返すとAiになるかをdist[Ai]とする
    vector<LL> dist(M,-1); dist[X] = 0;
    LL operation = 0;
    LL now = X;
    while(1){
        operation++;
        accum[operation] = accum[operation-1] + now;
        LL next = (now*now)%M;
        if(dist[next]!=-1){
            loop_start_Ai = next;
            operation_per_loop = operation - dist[next];
            sum_per_loop = accum[operation] - accum[dist[next]];
            accum[operation+1] = accum[operation] + next;
            break;
        }
        dist[next] = operation;
        now = next;
    }

   //cout << loop_start_Ai << "," << operation_per_loop << "," << sum_per_loop << endl;

    if(N<=operation) ans = accum[N];
    else{
        LL former_operation = dist[loop_start_Ai];
        LL numof_loop = (N-former_operation)/operation_per_loop;
        LL later_operation = (N-former_operation)%operation_per_loop;
        //cout << later_operation << endl;
        //                                                           ↓この項注意 later_operationはあくまでループから抜ける時の回数なので、ループに入るまでの操作回数を足さなければならない
        ans = accum[former_operation]  + numof_loop*sum_per_loop + (accum[former_operation+later_operation]-accum[former_operation]);
    }
}
 
int main(){
	cin >> N >> X >> M;
 
    solve();

	cout << ans << endl;
    return 0;
}