#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REPR(i,n) for (int i=(int)(n)-1;i>=0;--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
#define tpl(...) make_tuple(__VA_ARGS__)
const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;
const double PI = acos(-1);
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
typedef long long ll;
typedef pair<int,int> pii;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename Ch,typename Tr,typename C,typename=decltype(begin(C()))>basic_ostream<Ch,Tr>& operator<<(basic_ostream<Ch,Tr>&os,
const C& c){os<<'[';for(auto i=begin(c);i!=end(c);++i)os<<(i==begin(c)?"":" ")<<*i;return os<<']';}
template<class S,class T>ostream&operator<<(ostream &o,const pair<S,T>&t){return o<<'('<<t.first<<','<<t.second<<')';}
template<int N,class Tp>void output(ostream&,const Tp&){}
template<int N,class Tp,class,class ...Ts>void output(ostream &o,const Tp&t){if(N)o<<',';o<<get<N>(t);output<N+1,Tp,Ts...>(o,t);}
template<class ...Ts>ostream&operator<<(ostream&o,const tuple<Ts...>&t){o<<'(';output<0,tuple<Ts...>,Ts...>(o,t);return o<<')';}
template<class T>void output(T t,char z=10){if(t<0)t=-t,putchar(45);int c[20];
int k=0;while(t)c[k++]=t%10,t/=10;for(k||(c[k++]=0);k;)putchar(c[--k]^48);putchar(z);}
template<class T>void outputs(T t){output(t);}
template<class S,class ...T>void outputs(S a,T...t){output(a,32);outputs(t...);}
template<class T>void output(T *a,int n){REP(i,n)cout<<a[i]<<(i!=n-1?',':'\n');}
template<class T>void output(T *a,int n,int m){REP(i,n)output(a[i],m);}
template<class T>bool input(T &t){int n=1,c;for(t=0;!isdigit(c=getchar())&&~c&&c-45;);
if(!~c)return 0;for(c-45&&(n=0,t=c^48);isdigit(c=getchar());)t=10*t+c-48;t=n?-t:t;return 1;}
template<class S,class ...T>bool input(S&a,T&...t){input(a);return input(t...);}
template<class T>bool inputs(T *a, int n) { REP(i,n) if(!input(a[i])) return 0; return 1;}

ll gcd(ll a, ll b) {
  return b==0 ? a : gcd(b, a%b);
}

int s[100000];

int main() {
  int n;
  while(cin>>n) {
    inputs(s,n);
    ll ans = 0;
    for (int d=1; d<n; d++) {
      // if ((n-1-d) % d != 0) continue;
      int bk = d;
      ll bsum = 0;
      ll asum = 0;
      int ng = n;
      for (int k=n-1-d; k>0; k-=d) {
        // cout << tpl(d,k) << endl;
        // if (k <= bk) break;
        // if (k <= n-1-k && k % d == 0) break;
        // int g = gcd(k, k-d);
        // int A = k / g;
        // int B = (k-d) / g;
        // if (A == B + 1) {
        //   int num = (n - k) / d;
        //   if (num > A) break;
        // }
        int A = k;
        int B = A - d;
        if (A <= B || B <= 0) continue;
        if (k % d == 0) ng = k;
        if (ng <= bk) {
          break;
        }
        asum += s[k];
        bsum += s[bk];
        bk += d;

        chmax(ans, asum + bsum);
        // cout << tpl(A, B, k, bk, asum, bsum, asum + bsum) << endl;
        // A = k
        // d = A - B
        // B = A - d
        // (s[A] + S[A+d] ... S[n-1]) + (s[d] + s[2*d] + ... + s[n-1-A])

      }
    }
    cout << ans << endl;
  }
}
