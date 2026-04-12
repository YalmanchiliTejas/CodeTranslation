#pragma region Macros
#include <bits/stdc++.h>
using namespace std;

// debug methods
// usage: debug(x,y);
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0,a1,a2,a3,a4,x,...) x
#define debug_1(x1) cout<<#x1<<": "<<x1<<endl
#define debug_2(x1,x2) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<endl
#define debug_3(x1,x2,x3) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<endl
#define debug_4(x1,x2,x3,x4) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<endl
#define debug_5(x1,x2,x3,x4,x5) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<", "#x5<<": "<<x5<<endl
#ifdef LOCAL
    #define debug(...) CHOOSE((__VA_ARGS__,debug_5,debug_4,debug_3,debug_2,debug_1,~))(__VA_ARGS__)
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define debug(...) 42
    #define eprintf(...) 42
#endif

#define PI 3.1415926535897932384626433832795
#define INF 2e9
#define SINV(t) greater<t>()
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i, n) for(int i=(n); i>=0; --i)
#define FOR(i, n, m) for(int i=(m), i##_len=(n); i<i##_len; ++i)
#define FOREACH(i, v) for(auto i=(v).begin(); i!=(v).end(); ++i)
#define ALL(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;
#define vv(t) vector<t>

#define CHC(mp, x) if(mp.end() != mp.find(x))

#pragma endregion

template<typename T>
void SV(vector<T> v){
    REP(i,v.size()){
        #ifdef LOCAL
            cout << i << " : " << v[i] << endl;
        #endif
    }
}
int bitCount(int bits) {
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >> 16);
}

vv(vv(int)) mp(9);


int N, M;
int f(int num, int now){
    num = num | (1<<now);
    if((num>>1)+1 == 1<<N){
        debug("complete" ,now, num);
        return 1;
    }
    int sum = 0;
    REP(i, mp[now].size()){
        debug(now, i, mp[now][i]);
        if((num>>mp[now][i])&1){
            continue;
        }
        SV(mp[now]);
        sum += f(num, mp[now][i]);
    }
    return sum;
}

int main(void){
    cin >> N >> M;
    int a, b;
    REP(i, M){
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    //SV(mp[1]);
    cout << f(0, 1) << endl;
    return 0;
}
