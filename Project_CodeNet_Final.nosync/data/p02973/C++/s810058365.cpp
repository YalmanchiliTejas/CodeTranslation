#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <assert.h>
#include <unordered_set>
#include <random>



using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)














int main(){
    ll n;
    cin >> n;
    multiset<ll> st;
    REP(i, n){
        ll a;
        cin >> a;
        if(st.empty()){
            st.insert(a);
        }
        else{
            auto itr = st.lower_bound(a);
            if(itr == st.begin()){
                st.insert(a);
            }
            else{
                itr--;
                st.erase(itr);
                st.insert(a);
            }
        }
    }
    cout << st.size() << endl;
}
