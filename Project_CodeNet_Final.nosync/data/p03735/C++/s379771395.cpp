#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define int long long
#define INF 1000000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);



signed main(){

    int N; cin >> N;
    vec x(N), y(N);
    REP(i, N) cin >> x[i] >> y[i];
    int m = INF, M = 0;
    REP(i, N){
        m = min(m, min(x[i], y[i]));
        M = max(M, max(x[i], y[i]));
    }

    int m2 = m, M2 = M;
    REP(i, N){
        m2 = max(m2, min(x[i], y[i]));
        M2 = min(M2, max(x[i], y[i]));
    }
    int ans1 = (M - M2) * (m2 - m);

    vector<Pii> p(N);
    REP(i, N) p[i] = Pii(min(x[i], y[i]), max(x[i], y[i]));
    SORT(p);
    int l = p[N - 1].first - p[0].first;
    int mm = INF, MM = p[N - 1].first;
    REP(i, N){
        mm = min(mm, p[i].second);
        MM = max(MM, p[i].second);
        int mm2 = mm;
        if(i < N - 1) mm2 = min(mm, p[i + 1].first);
        l = min(l, MM - mm2);
    }
    int ans2 = (M - m) * l;

    cout << min(ans1, ans2);
    
    return 0;
}


template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}