#include <bits/stdc++.h>
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
#define all(x) (x).begin(),(x).end()

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}

template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(10);
    int N,M;
    cin >> N >> M;
    if(N == M)cout <<"Yes"<< "\n";
    if(N != M)cout <<"No"<< "\n";
}