#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <list>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip> // setprecisionを使用するのに必要 cout << fixed << setprecision(15) << p でpを小数点以下15桁表示
using namespace std;
#define REPD(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) REPD(i, 0, n)
#define DIV0 1000000007
typedef long long ll;
#define fin(ans) cout << (ans) << '\n'
/*

*/
int main()
{
    int N;
    cin >> N;
    ll A[N];
    REP(i,N) cin >> A[i];

    //総和をとってかけて、対角要素を引いて、2で割る
    
    /*ll ans = 0;
    REP(i,N) ans = (ans + A[i])%DIV0;
    ans = (ans * ans)%DIV0;
    REP(i,N) ans = (ans - A[i]*A[i] + DIV0)%DIV0;
    ans = (ans/2 + DIV0)%DIV0;*/
    ll sum[N];
    sum[0] = A[0];
    REPD(i,1,N) sum[i] = (sum[i-1] + A[i])%DIV0;
    ll ans = 0;
    REPD(i,1,N) ans = (ans + A[i] * sum[i-1])%DIV0;

    fin(ans);
    return 0;
}