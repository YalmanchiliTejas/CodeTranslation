#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1010000000000000017LL;
const ll MOD = 1000000007LL;

#define REP(i, n) for(ll i = 0 ; i < n; i++)

//#define DEBUG(fmt, ...)
#define DEBUG(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)

int main(){
    std::cout<<std::fixed<<std::setprecision(10);

    ll N;

    cin >> N;

    multiset<ll> maxes;

    REP(i, N){
        ll A;
        cin >> A;
        auto it = maxes.lower_bound(A);
        if( maxes.empty() || it == maxes.begin() ){
        }else{
            it--;
            maxes.erase(it);
        }
        maxes.insert(A);
    }


    cout << maxes.size() << endl;
}
