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
    int N;
    cin >> N;
    int H[N+10];
    REP(i,N){
        cin >> H[i];
    }
    int res = 1;
    FOR(i,1,N){
        bool great = false;
        REP(j,i){
            if(H[i]<H[j]){
                great = true;
                break;
            }
        }
        if(great == false) res++;
    }
    cout << res << endl;
    return 0;
}