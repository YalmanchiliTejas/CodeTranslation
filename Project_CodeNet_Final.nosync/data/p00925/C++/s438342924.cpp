#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
#define tpl(...) make_tuple(__VA_ARGS__)
const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;
const double PI = acos(-1);
typedef long long ll;
typedef pair<int,int> pii;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>ostream&operator<<(ostream &o,const vector<T>&t){o<<'[';FOR(i,t){if(i!=t.begin())o<<',';o<<*i;}return o<<']';}
template<class S,class T>ostream&operator<<(ostream &o,const pair<S,T>&t){return o<<'('<<t.first<<','<<t.second<<')';}
template<int N,class Tp>void output(ostream&,const Tp&){}
template<int N,class Tp,class,class ...Ts>void output(ostream &o,const Tp&t){if(N)o<<',';o<<get<N>(t);output<N+1,Tp,Ts...>(o,t);}
template<class ...Ts>ostream&operator<<(ostream&o,const tuple<Ts...>&t){o<<'(';output<0,tuple<Ts...>,Ts...>(o,t);return o<<')';}
template<class T>void output(T t,char z=10){if(t<0)t=-t,putchar(45);int c[20];
int k=0;while(t)c[k++]=t%10,t/=10;for(k||(c[k++]=0);k;)putchar(c[--k]^48);putchar(z);}
template<class T>void outputs(T t){output(t);}
template<class S,class ...T>void outputs(S a,T...t){output(a,32);outputs(t...);}
template<class T>void output(T *a,int n){REP(i,n)output(a[i],i!=n-1?',':10);}
template<class T>void output(T *a,int n,int m){REP(i,n)output(a[i],m);}
template<class T>bool input(T &t){int n=1,c;for(t=0;!isdigit(c=getchar())&&~c&&c-45;);
if(!~c)return 0;for(c-45&&(n=0,t=c^48);isdigit(c=getchar());)t=10*t+c-48;t=n?-t:t;return 1;}
template<class S,class ...T>bool input(S&a,T&...t){input(a);return input(t...);}

char s[1010];

ll term(int &i);
ll fact(int &i);

ll exp(int &i) {
  ll p = term(i);
  while(s[i]=='+' || s[i]=='-') {
    char c = s[i++];
    if (c == '+') {
      ll a = term(i);
      p += a;
    }
    else p -= term(i);
  }
  return p;
}

ll term(int &i) {
  ll p = fact(i);
  while(s[i]=='*') {
    i++;
    p *= fact(i);
  }
  return p;
}

ll exp2(int &i) {
  ll p = fact(i);
  while(s[i]=='+' || s[i]=='-' || s[i]=='*') {
    char c = s[i++];
    if (c == '+') {
      ll a = fact(i);
      p += a;
    }
    else if (c == '-') p -= fact(i);
    else {
      p *= fact(i);
    }
  }
  return p;
}

ll fact(int &i) {
  if (s[i] == '(') {
    i++;
    int p = exp(i);
    assert(s[i++]==')');
    return p;
  } else {
    int num = 0;
    while(isdigit(s[i])) {
      num *= 10;
      num += s[i]-'0';
      i++;
    }
    return num;
  }
}


int main() {
  while(cin >> s) {
    ll x;
    cin >> x;
    int i = 0;
    ll ans1 = exp(i);
    i = 0;
    ll ans2 = exp2(i);
    // cout << ans1 << " " << ans2 << endl;
    char ans;
    if (ans1 == x && ans2 == x) {
      ans = 'U';
    } else if (ans1 == x) {
      ans = 'M';
    } else if (ans2 == x) {
      ans = 'L';
    } else {
      ans = 'I';
    }
    cout << ans << endl;
  }
}