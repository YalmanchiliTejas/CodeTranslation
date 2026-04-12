#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define pb push_back
#define ff first
#define ss second
#define BS binary_search
#define all(c) (c).begin(),(c).end()
#define sz(x) (int)(x).size()
#define EPS 0.000000001 //1e-9
using pii=pair<int,int>;
const long long INF=1e18;

template <class A, class B> ostream& operator<<(ostream& os, const pair<A,B> p) {return os << "(" << p.first << "," << p.second << ")";} 

void dprint(string s) {cout << endl;}
template <class T, class... U> void dprint(string s, T t, U... u) 
{int w = s.find(','); cout << "[" << s.substr(0,w) << ": " << t << "] "; dprint(s.substr(w+1, (int)s.size()-w), u...);} 

#define DEBUG 
#ifdef DEBUG
#define dbg(X...) dprint(#X,X)
#else
#define dbg(X...) "KEEP CALM" 
#endif

const int N=1e6+5; // Don't forget to CHANGE this value ACC. TO Q.

int32_t main()
{
    IOS;
    int x; cin>>x;
    if(x>=30)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}