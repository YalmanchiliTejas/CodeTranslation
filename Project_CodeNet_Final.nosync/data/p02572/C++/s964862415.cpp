#define _USE_MATH_DEFINES
 
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
constexpr ll MOD = 1000000007;
 
#ifndef ONLINE_JUDGE
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " (" << x.first << " : " << x.second << ")" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const multiset<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "["; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "]"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "(" << obj.first << ", " << obj.second << ")"; return o;}
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
void print_sim_py(void) {cout << endl;}
template <class Head> void print_sim_py(Head&& head) {cout << head;print_sim_py();}
template <class Head, class... Tail> void print_sim_py(Head&& head, Tail&&... tail) {cout << head << " ";print_sim_py(forward<Tail>(tail)...);}
 
#define print(...) print_sim_py(__VA_ARGS__);
#else
#define print(...);
#endif


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n;
    ll ans=0;

    cin >> n;

    vector<ll> a(n);
    ll sum_all = 0;

    for(auto&& x : a){
        cin >> x;
        sum_all=(sum_all+x)%MOD;
    }

    for(ll i=0; i<n; i++){
        sum_all -= a[i];
        if(sum_all<0)sum_all+=MOD;

        ll mul = (a[i]*sum_all)%MOD;
        ans = (ans+mul)%MOD;
    }
    
    cout << ans << endl;
 
    return 0;
}

