#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
using ll=long long;

const ll INF = pow(10,18)+1;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

template<typename T> bool chmin(T& a, T b) {return a > b ? a = b, true : false;}
template<typename T> bool chmax(T& a, T b) {return a < b ? a = b, true : false;}
 
int main(){
    int N, K;
    string S;
    cin >> N >> S >> K;
    string res = "";
    REP(i,N){
        if(S.substr(i,1)!=S.substr(K-1,1)) res += "*";
        else res += S.substr(i,1);
    }
    cout << res << endl;
    return 0;
}