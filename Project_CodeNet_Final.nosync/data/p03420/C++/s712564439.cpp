//Create Time: 2018-04-28 13:44:10
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <functional>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>
#include <complex>
#include <cassert>
#include <climits>
#include <iterator>
#include <tuple>
using namespace std;
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,n,a) for (int i=(n)-1;i>=(a);i--)
// #define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
// #define TST(x) std::cout<<(#x)<<":"<<(x)<<" "
#define OUT(args...) {string _s=#args;replace(_s.begin(),_s.end(),',',' ');stringstream _ss(_s);istream_iterator<string> _it(_ss);OUT_TST("\n",_it,args);}
#define TST(args...) {string _s=#args;replace(_s.begin(),_s.end(),',',' ');stringstream _ss(_s);istream_iterator<string> _it(_ss);OUT_TST("",_it,args);}
#define SZ(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define mem(f,x) memset((f), (x), sizeof(f))
#define clr(f) mem(f,0)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define eb emplace_back
#define DEBUG
void OUT_TST(string s,istream_iterator<string> it) {cerr<<s;}
template<typename T, typename... Args> void OUT_TST(string s,istream_iterator<string> it,T a,Args... args){cerr<<*it<<"="<<a<<" ";OUT_TST(s,++it,args...);}
template<class T> void rd(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long powmod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef tuple<int,int,int> tp;
/****head****/
int main(){
    int n,K;cin>>n>>K;
    ll ans=0;
    rep(t,K,n){
        int i=t+1,j,k=2;
        for(;i<=n;i=j+1){
            k=(n-t)/i;
            if(k==0)j=n;
            else j=(n-t)/k;
            if(t) ans+=(ll)(j-i+1)*(k+1);
            else ans+=(ll)(j-i+1)*k;
            // OUT(t,i,j,k,ans);
        }
        // if(i<=n)ans+=n-i+1;
    }
    cout<<ans<<endl;
    return 0;
}
