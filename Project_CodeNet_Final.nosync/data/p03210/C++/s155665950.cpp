#include <bits/stdc++.h>
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

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
    int N;
    cin >> N;
    if(N == 7 || N == 5 || N == 3){
        cout <<"YES"<< "\n";
    }else{
        cout <<"NO"<< "\n";
    }
}