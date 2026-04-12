#include <bits/stdc++.h>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
using ld = long double;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    ll N, M, i, a[100], b[100], link[10][10]={0}, ans=0, judge;

    cin >> N >> M;

    vector<ll> v(N);

    for(i=1; i<=M; i++){
        cin >> a[i] >> b[i];
        link[a[i]][b[i]] = 1;
    }

    for(i=0; i<N; i++){
        v[i] = i+1;
    }

    do{
        judge = 1;

        for(i=0; i<N-1; i++){
            if(link[v[i]][v[i+1]]==0 && link[v[i+1]][v[i]]==0){
                judge = 0;
            }
        }
        if(v[0]!=1) judge = 0;

        if(judge==1) ans++;

    }while(next_permutation(v.begin(), v.end()));

    cout << ans << endl;

    return 0;
}