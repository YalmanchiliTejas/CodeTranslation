#include <bits/stdc++.h>
//#include <atcoder/all>

using namespace std;
//using namespace atcoder;
 
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

//*
#define mod 1000000007 /*/
#define mod 998244353 //*/

typedef pair<int, int> P;
#define INF (1LL<<60)


void solve(){
    int N, X, M;
    cin >> N >> X >> M;
    vector<int> A;
    set<int> alln;
    
    int head = 0, loop = 0;
    for(int _=0; _<N; _++){
        if(_==0){
            A.push_back(X);
            alln.insert(X);
            continue;
        }
        int t =A.back()*A.back() % M;
        A.push_back(t);
        if(alln.find(t)!=alln.end()){
            dump(_,t); dump(A);
            for(int i=0; i<(int)A.size()-1; i++){
                if(A[i]==t){ head = i+1; loop = _-i; goto b;}
            }
        }
        alln.insert(t);
    }
b:
    
    int headsum = 0, loopsum=0;
    vector<int> loopelement;
    for(int i=0; i<head; i++) headsum += A[i];
    for(int i=head; i<head+loop; i++){
        loopsum += A[i];
        loopelement.push_back(A[i]);
    }

    dump(head, loop, loopelement);

    
    int ans = 0;
    if(loop == 0){
        rep(i,N) ans += A[i];
    }else{
        ans += ((N-head)/loop) * loopsum + headsum;
        for(int i=0; i<(N-head)%loop; i++) ans += loopelement[i];
    }
    cout << ans << endl;
}


signed main(){
    cout << fixed << setprecision(18);
    cerr << fixed;
    solve();
}
