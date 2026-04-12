#include <bits/stdc++.h>
 
#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)
 
#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=(int)(a)-1;i>=(int)(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)
 
#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
 
// #define DEBUG
 
#ifdef DEBUG
    #define dump(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dump(...)
#endif
 
template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}
 
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
 
const double EPS = 1e-10;
const double PI = acos(-1.0);
const ll inf =1LL << 62;
const ll mod=1000000007LL;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
 
 
ll extgcd(ll a,ll b,ll& x,ll& y){x=1,y=0;ll g=a;if(b!=0) g=extgcd(b,a%b,y,x),y-=a/b*x;return g;}
ll ADD(const ll &a, const ll &b,const ll &mod) { return (a+b)%mod;}
ll SUB(const ll &a, const ll &b,const ll &mod) { return (a-b+mod)%mod;}
ll MUL(const ll &a, const ll &b,const ll &mod) { return (1LL*a*b)%mod;}
ll DIV(const ll &a, const ll &b,const ll &mod) {ll x,y; extgcd(b,mod,x,y);return MUL(a,(x+mod)%mod,mod);}
 
random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dice(1,6);
uniform_real_distribution<double> score(0.0,10.0);

int parse(string& formula){
    int idx = 0;
    int ret = 0;

    int len = formula.size();
    while(idx < len){
        int diff = formula[idx] - '0';
        idx++;

        if(idx >= len){
            ret += diff;
            break;
        }

        char op = formula[idx];
        idx++;
        while(op == '*'){
            int cur = formula[idx] - '0';
            idx++;
            diff *= cur;

            if(idx >= len) break;
            op = formula[idx];
            idx++;
        }

        ret += diff;
    }

    return ret;
}

int main(void){
    string in; cin >> in;
    int bob_res; cin >> bob_res;

    int l_res = in[0] - '0';
    int len = in.size();
    rep(i, 1, len){
        char op = in[i];
        i++;

        int cur = in[i] - '0';
        switch(op){
            case '*': { l_res *= cur; break; }
            case '+': { l_res += cur; break; }
        }
    }
    int f_res = parse(in);

    char res = 'I';
    if(l_res == bob_res and f_res == bob_res){
        res = 'U';
    }
    else if(l_res == bob_res){
        res = 'L';
    }
    else if(f_res == bob_res){
        res = 'M';
    }

    cout << res << endl;

    return 0;
}