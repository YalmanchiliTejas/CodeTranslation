#define LOCAL
#include <iostream>
#include <map>
#include <iterator>
#include <bits/stdc++.h>
#include <stdbool.h>
#include <math.h>
#define io() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define show(x)     cout << (#x) << ":" << x << endl;
#define show2(x,y)  cout << (#x) << ":" << x << " " << (#y) << ":" << y << endl;
#define ll long long
#define ld long double
#define mp make_pair
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define en "\n"
#define rep(i,a,b) for(int (i)=(a);(i) < (b); (i)++)
using namespace std;

template<class T> ostream& operator<<(ostream &os, vector<T> V){os << "[ "; for(auto v  : V) os << v << " "; return os << "]";}
template<class T> ostream& operator<<(ostream &os, set<T> V){os << "[ "; for(auto v  : V) os << v << " "; return os << "]";}
template<class T , class R > ostream& operator<<(ostream &os, map<T , R> V){os << "[ "; for(auto v  : V) os << "(" << v.first << ":" << v.second << ")"; return os << "]";}
template<class T , class R > ostream& operator<<(ostream &os, pair<T , R> V){return os << "(" << V.first << "," << V.second << ")";}
 
#define cerr cout
#ifdef LOCAL
    #define TRACE
#endif
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){cerr << "T->";cerr << name << " : " << arg1 << endl;}
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){cerr << "T->";const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | "; __f(comma+1, args...);}
    clock_t clk=clock();
    #define checktime() cout<<"\nTime Elapsed : "<<float(clock()-clk)/CLOCKS_PER_SEC<<endl
#else
    #define trace(...);
    #define checktime();
#endif

#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<"\n"
#define d2(x,y) cout<<(x)<<" "<<(y)<<"\n"
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<"\n"
#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<"\n"
#define d5(a,b,c,d,e) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<"\n"
#define d6(a,b,c,d,e,f) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<" "<<(f)<<"\n"
#define print(a) for(auto x:a) cout<<x<<" "; cout<<"\n"; 
// Use max({a,b,c,d,....}) instead
// #define max3(a,b,c) max(max((a),(b)),(c))
// #define max4(a,b,c,d) max(max((a),(b)),max((c),(d)))

const ll MOD = 1000 * 1000 * 1000 + 7;
const ll MOD1 = 998244353;


void solve(){
    int x;
    cin>>x;
    if(x>=30)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}

int main() {
    io();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //int t;
    //#pragma comment(linker, "/STACK:2000000")
    //cin>>t;
    //rep(i,0,t){
        solve();
    //}
    //h=1;
    return 0;
}