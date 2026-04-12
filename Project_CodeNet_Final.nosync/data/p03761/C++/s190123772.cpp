#include<bits/stdc++.h>

using namespace std;

#define debug(n) cerr << #n << ':' << n << endl;
#define dline    cerr << __LINE__ << endl;

using ll = long long;
using ull = unsigned long long;
template<class T, class U> using P = pair<T,U>;
template<class T> using Heap = priority_queue<T>;
template<class T> using heaP = priority_queue<T,vector<T>,greater<T>>;
template<class T,class U> using umap = unordered_map<T,U>;
template<class T> using uset = unordered_set<T>;

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
  modint& operator+=(const modint&b)
  {    return (*this) = (*this) + b;  }
  modint& operator-=(const modint&b)
  {    return (*this) = (*this) - b;  }
  modint& operator*=(const modint&b)
  {    return (*this) = (*this) * b;  }
  modint& operator/=(const modint&b)
  {    return (*this) = (*this) / b;  }
  modint& operator++()
  {    (*this)+=1; return (*this);  }
  modint& operator--()
  {    (*this)-=1; return (*this);  }
  modint operator++(int){
    modint tmp(*this);
    ++(*this);
    return tmp;
  }
  modint operator--(int){
    modint tmp(*this);
    --(*this);
    return tmp;
  }    
  modint pow(unsigned long long i){
    if(i == 0) return 1;
    if(i & 1){
      return (*this) * (this->pow(i-1));
    }
    modint<mod>hpow = (this->pow(i>>1));
    return hpow * hpow;
  }
  friend ostream& operator<<(ostream&os, const modint&a){
    os << a.num;
    return os;
  }
  friend istream& operator>>(istream&is, modint&a){
    long long x; is >> x;
    a = x;
    return is;
  }
};

using mint = modint<1000000007>;

template<ll mod>
struct Factorial{
  const int size;
  vector<modint<mod>> v;
  Factorial(int n):size(n+1),v(vector<modint<mod>>(n+1,1)){
    for(int i = 1; i < size; ++i){
      v[i] = v[i-1] * i;
    }
  }
  modint<mod> operator[](const int idx) const {
    if(idx >= size){
      cerr << "Factorial operator[] idx >= size:" << idx << endl;
      return 1;
    }
    if(idx < 0){
      cerr << "Factorial operator[] idx < 0:" << idx << endl;
      return 1;
    }
    return v[idx];
  }
};

Factorial<1000000007> fact(100005);

int main(){
  int n; cin >> n;
  map<char,int> mp;
  for(char c = 'a'; c <= 'z'; ++c){
    mp[c] = 1001001001;
  }
  for(int i = 0; i < n; ++i){
    string s; cin >> s;
    map<char,int> mmp;
    for(auto e:s){
      mmp[e]++;
    }
    for(char c = 'a'; c <= 'z'; ++c){
      ChangeMin(mp[c],mmp[c]);
    }
  }
  for(auto e:mp){
    cout << string(e.second,e.first);
  }
  cout << endl;
}
