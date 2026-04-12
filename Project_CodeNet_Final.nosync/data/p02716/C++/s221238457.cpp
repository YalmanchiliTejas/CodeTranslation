#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<class F>auto recursive(F f){return[f](auto...a){return f(f,a...);};}
template<class I,class V=typename I::value_type>V sum_up(const I&l,const I&r){V v;for(I i=l;i!=r;i++)v=i==l?*i:v+*i;return v;}
template<class I,class T=iterator_traits<I>>I operator+(I it,int n){for(int i=0;i<n;i++)it++;return it;}
template<class I,class T=iterator_traits<I>>I operator-(I it,int n){for(int i=0;i<n;i++)it--;return it;}
template<class T>using rev_priority_queue=priority_queue<T,vector<T>,greater<T>>;
template<class T>using vector2d=vector<vector<T>>;
struct fixprec{int p;fixprec(int p):p(p){}};
ostream&operator<<(ostream&o,fixprec f){return o<<fixed<<setprecision(f.p);}
void R_YESNO(bool p){cout<<(p?"YES":"NO")<<endl;}
void R_YesNo(bool p){cout<<(p?"Yes":"No")<<endl;}
int main() {
    const i64 INF = 1e16;
    int N;
    cin >> N;
    vector<int> A(N);
    for(int &a : A) cin >> a;
    int X = N - 2 * (N / 2) + 1;
    vector2d<i64> dp(X + 1, vector<i64>(N, -INF));
    for(int i = X; i >= 0; i--) {
        dp[X - i][i] = A[i];
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= X; j++) {
            for(int k = 0; k <= j; k++) {
                int l = i + 2 + (j - k);
                if(l >= N) continue;
                dp[k][l] = max(dp[k][l], A[l] + dp[j][i]);
            }
        }
    }
    i64 ans = -INF;
    for(int i = 0; i <= X; i++) {
        ans = max(ans, dp[i][N - 1 - i]);
    }
    cout << ans << endl;
    return 0;
}

