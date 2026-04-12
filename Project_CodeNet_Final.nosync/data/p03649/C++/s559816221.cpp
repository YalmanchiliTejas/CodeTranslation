#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define int long long
#define INF 1000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);

signed main(){

    int N; cin >> N;
    vec a(N); readvec(a);

    int ans = 0;
    while(true){
        int tmp = 0;
        REP(i, N){
            if(a[i] <= N - 1) continue;
            int n = (a[i] - (N - 1)) / N + min((int)1, (a[i] - (N - 1)) % N);
            tmp += n;
            a[i] -= n * (N + 1);
            REP(j, N) a[j] += n;
        }
        if(tmp == 0) break;
        ans += tmp;
    }

    cout << ans;
    
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