#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; ++i)
#define REPR(i, n) for(int i = n; i >= 0; --i)
#define FOR(i, m, n) for(int i = m; i < n; ++i)
#define FORR(i, m, n) for(int i = m; i >= n; --i)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)

#define INF 999999999

using namespace std;

typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

int dx[]={1, -1, 0, 0, 0};
int dy[]={0, 0, 1, -1, 0};

int main(){
    cin.tie(0); //cinとcoutの同期切り
    ios::sync_with_stdio(false); //iostreamとstdioの同期切り

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = 0;
    if(A + B <= C*2){
        ans = X*A + Y*B;
    }
    else{
        int m = min(X, Y);
        ans += m*C*2;
        if(X > m) ans += (X - m)*A;
        else if (Y > m) ans += (Y - m)*B;
        
        ans = min(ans, C*2*max(X, Y));
    }

    cout << ans << endl;

    return 0;
}

/*****************************************************************************/
/*****   1秒間で処理できるfor文ループの回数                                 *****/
/*****   → 10^8 = 100,000,000 回程度                                      *****/
/*****                                                                   *****/
/*****   sort(a, a+N, greater<int>()); // a[0:N) を大きい順にソート        *****/
/*****                                                                   *****/
/*****                                                                   *****/
/*****   std::cout << std::setprecision(2) << 3.0; // "3"                *****/
/*****   std::cout << std::fixed;                                        *****/
/*****   std::cout << std::setprecision(2) << 3.0; // "3.00"             *****/
/*****                                                                   *****/
/*****************************************************************************/