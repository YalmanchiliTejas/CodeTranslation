#include <bits/stdc++.h>
using namespace std;
 
//////////////////

#ifdef DEBUG
    #include "debug.h"
    #define dump(...)                                                              \
        DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                            \
                << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]"        \
                << endl                                                            \
                << "    ",                                                         \
            dump_func(__VA_ARGS__)
#else
    #define dump(...)
#endif


// http://beet-aizu.hatenablog.com/entry/2018/04/08/145516
template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
  for(auto &e:t) fill_v(e,v);
}

//////////////////

#define int long long
 
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

#define YES puts("YES")
#define Yes puts("Yes")
#define NO  puts("NO")
#define No  puts("No")
#define ALL(v) (v).begin(), (v).end()
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

/*
#define mod 1000000007 /*/
#define mod 998244353 //*/

typedef pair<int, int> P;
#define INF (1LL<<60)


void solve(){
    int X;
    cin >> X;
    if(X>=30) Yes;
    else No;
    
}


signed main(){
    cout << fixed << setprecision(18);
    cerr << fixed << setprecision(18);
    solve();
}
