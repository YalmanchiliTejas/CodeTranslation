#include <bits/stdc++.h>
#ifdef tester
    #include "prettyprint.hpp"
#endif
using namespace std;

#define hell 1000000007
#define ll long long
#define all(C) begin(C),end(C)
#define tr(C,it,cond) for(auto it = begin(C); cond and it!=end(C); ++it)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb push_back
#define hash unordered_map
#define vi vector<ll>
#define pii pair<ll,ll>
#define index(V, ele) distance(V.begin(), find(all(V), ele))
#define N 100005

#define whats(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {} template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
#ifdef tester 
    cerr << *it << " = " << a << endl;	err(++it, args...); 
#endif 
}

ll t,n,k,m,q;
string s;

// vim cli: !g++ -Dtester sol.cpp ; ./a.out ; rm a.out
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    cin >> n;
    if (n==3 or n==5 or n==7)
        cout << "YES";
    else
        cout << "NO";
    // whats(t,v);
    return 0;
}