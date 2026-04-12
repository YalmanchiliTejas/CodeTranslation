#include<bits/stdc++.h>

using namespace std;

#define debug(n) cerr << #n << ':' << n << endl;
#define dline    cerr << __LINE__ << endl;
#define rep(i,s,e) for(ll i = (int)(s); i < (int)(e); ++i)
#define per(i,s,e) for(ll i = (int)(s)-1; i >= (int)(e); --i)

using ll = long long;
template<class T, class U> using P = pair<T,U>;
template<class T> using Heap = priority_queue<T>;
template<class T> using heaP = priority_queue<T,vector<T>,greater<T>>;

template<class T>
bool ChangeMax(T&a,const T&b){
  if(a >= b) return false;
  a = b;    return true;
}

template<class T>
bool ChangeMin(T&a,const T&b){
  if(a <= b) return false;
  a = b;    return true;  
}

template<class T, size_t N, class U>
void Fill(T (&a)[N], const U&v){
    fill((U*)a,(U*)(a+N),v);
}

template<class T>
istream& operator >> (istream&is, vector<T>&v){
  for(auto&e:v)is >> e;
  return is;
}

template<long long mod>
class modint{
private:
  long long num;
  long long extgcd(long long a, long long b, long long&x, long long&y)const {
    long long d = a;
    if(b != 0){d = extgcd(b, a%b, y, x);  y -= (a/b) * x;}
    else{x = 1; y = 0;}
    return d;
  }
  long long modinverse()const{
    long long x, y;
    extgcd(num, mod, x, y);
    return (mod + x%mod)%mod;
  }
public:
  modint():num(0){}
  modint(const long long x):num((x < 0?(x+mod):x)%mod ){}
  friend modint operator+(const modint&a, const modint&b)
  {    return modint(a.num + b.num);  }
  friend modint operator-(const modint&a, const modint&b)
  {    return modint(a.num - b.num);  }
  friend modint operator*(const modint&a, const modint&b)
  {    return modint(a.num * b.num);  }
  friend modint operator/(const modint&a, const modint&b)
  {    return modint(a*b.modinverse());  }
  friend ostream& operator<<(ostream&os, const modint&a){
    os << a.num;
    return os;
  }
};
const ll mod = 7 + (1e+9);
using MI = modint<mod>;

int main(){
  ll n,m,k; cin >> n >> m >> k;
  MI sumx = 0, sumy = 0;
  rep(i,1,n)sumx = sumx + i * (n - i) * m * m;
  rep(i,1,m)sumy = sumy + i * (m - i) * n * n;
  MI acb;
  {
    MI a=1; MI x = n*m-2;
    rep(i,0,k-2){
      a = a * x;
      x = x - 1;
    }
    MI b=1;
    rep(i,1,k-1)b = b * i;
    acb = a/b;
  }
  debug(sumx);
  debug(sumy);
  debug(acb);
  cout << (sumx+sumy)*acb << endl;
  
  return 0;
}
