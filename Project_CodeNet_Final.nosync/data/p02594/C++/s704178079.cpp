#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()
template<class T>
using reverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;

const string YES = "Yes";
const string NO = "No";

int main(){
    ll x;
    cin >> x;
    if(x >= 30){
        cout << YES << endl;
    }else{
        cout << NO << endl;
    }
    
    return 0;
}
