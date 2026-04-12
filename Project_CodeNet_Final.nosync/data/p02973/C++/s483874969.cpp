#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    REP(i,N){
        ll a;
        cin >> a;
        A[i] = a;
    }

    int ans = 0;

    //set<ll> se;
    map<ll, int> ma;
    for(int i = 0; i < N; i++){
        ll a = A[i];
        //auto last = se.end();
        //auto it = se.upper_bound(-a);
        auto last = ma.end();
        auto it = ma.upper_bound(-a);
        if(it != last){
            //se.erase(*it);
            ma[it->first]--;
            if(ma[it->first] == 0) ma.erase(it->first);
        }
        else{
            ans++;
        }
        //se.insert(-a);
        ma[-a]++;
    }

    cout << ans << endl;
    return 0;
}
