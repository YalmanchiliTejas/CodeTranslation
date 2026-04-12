#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i <b; i++)
using pii = pair<int,int>;
#define all(a) a.begin(), a.end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int N, M; cin >> N >> M;
    if(N == M) puts("Yes");
    else puts("No");
}