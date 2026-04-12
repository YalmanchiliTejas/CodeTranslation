#include <bits/stdc++.h>
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define pr(...) cerr<< GET_MACRO(__VA_ARGS__,pr6,pr5,pr4,pr3,pr2,pr1)(__VA_ARGS__) <<endl
#define pr1(a) (#a)<<"="<<(a)<<" "
#define pr2(a,b) pr1(a)<<pr1(b)
#define pr3(a,b,c) pr1(a)<<pr2(b,c)
#define pr4(a,b,c,d) pr1(a)<<pr3(b,c,d)
#define pr5(a,b,c,d,e) pr1(a)<<pr4(b,c,d,e)
#define pr6(a,b,c,d,e,f) pr1(a)<<pr5(b,c,d,e,f)
#define pr7(a,b,c,d,e,f,g) pr1(a)<<pr6(b,c,d,e,f,g)
#define pr8(a,b,c,d,e,f,g,h) pr1(a)<<pr7(b,c,d,e,f,g,h)
using namespace std;
using Int = long long;
using ll = long long;
using Double = long double;
const Int INF = (1LL<<55)+1e9; // ~ 3.6 * 1e16
const Int mod = (1e9)+7;
const Double EPS = 1e-8;
const Double PI = 6.0 * asin((Double)0.5);
using P = pair<Int,Int>;
using T = tuple<Int,Int,Int>;
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}
ostream& operator<<(ostream& o,P p){return o<<"("<<p.first<<","<<p.second<<")";}
ostream& operator<<(ostream& o,T t){return o<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")";}
istream& operator>>(istream& i,P &p){return i>>p.first>>p.second;}
ostream& operator<<(ostream& o,vector<auto> &a){Int i=0;for(auto t:a)o<<(i++?" ":"")<<t;return o;}
istream& operator>>(istream& i,vector<auto> &a){for(auto &t:a)i>>t;return i;}
void prArr(auto a,string s=" "){Int i=0;for(auto t:a)cout<<(i++?s:"")<<t;cout<<endl;}

class RMAQ{
public: 
  
  //遅延用の型  
  struct T{
    bool type; //0 - empty   , 1 - update
    Int value;
    T():type(0),value(0){}
    T(bool type,Int value):type(type),value(value){}
  };

  //比較可能な主データ型
  struct D{
    Int value;
    D():value(0){} /*適切な値にする!!!!!!*/
    D(Int value):value(value){}
    bool operator < (D a)const {return value < a.value;} //merge用
  };
  
  D INF = D(1LL<<55); /*!!!!!!!!!!!!!!!!!!!!!!!!*/

  Int n;
  vector<D> dat;
  vector<T> td;
  Int toMax; //0 -> RangeMin, 1 -> RangeMax
  
  RMAQ(){n=-1;}
  RMAQ(Int n_,Int toMax = 0){
    this->toMax = toMax;
    n=1;
    while(n<n_)n*=2;
    td.resize(2*n-1,T());
    dat.resize(2*n-1,D());
  }
  
  D merge(D a,D b){return min(a,b);}
  
  void delay(Int k){
    if(td[k].type==0) return;
    Int v = td[k].value;
    td[k].type = 0;
    td[k].value = 0;
    
    Int l = k*2+1,r = k*2+2;
    dat[l].value += v; td[l].type = 1; td[l].value += v;
    dat[r].value += v; td[r].type = 1; td[r].value += v;
  }

  D update(Int k,Int x){
    td[k].type = 1;
    td[k].value += x;
    dat[k].value += x;
    return dat[k];
  }
  
  //[a,b)の値をx加算　add(a,b,x)
  D add(Int a,Int b,Int x,bool flg=true,Int k=0,Int l=0,Int r=-1){
    if(r==-1 && toMax) x *= -1; 
    if(r==-1) r=n, assert(a <= n && b <= n);
    if(r<=a||b<=l) return flg? dat[k]:INF;
    if(a<=l&&r<=b) return flg? update(k,x):dat[k];
    
    delay(k);
    D vl = add(a,b,x,flg,k*2+1,l,(l+r)/2);
    D vr = add(a,b,x,flg,k*2+2,(l+r)/2,r);
    if(flg) dat[k] = merge(vl,vr);
    return merge(vl,vr);
  }
  
  //[a,b)の最小値を得る　find(a,b);
  Int find(Int a,Int b){
    D res = add(a,b,0,false);
    if(toMax) res.value *= -1; 
    return res.value;
  }
};

Int valid(string s){
  Int n = s.size();
  Int cnt = 0;
  for(Int i=0;i<n;i++){
    if(s[i] == '(') cnt++;
    if(s[i] == ')') cnt--;
    if(cnt < 0) return false;
  }
  return cnt == 0;
}

signed main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);
  Int n, q;
  cin>>n>>q;
  string s;
  cin>>s;

  RMAQ A(n);
  Int cnt = 0;
  for(Int i=0;i<n;i++){
    if(s[i] == '(') cnt++;
    if(s[i] == ')') cnt--;
    A.add(i, i+1, cnt);
  }

  set<Int> open;
  set<Int> close;
  for(Int i=0;i<n;i++) s[i] == '('? open.insert(i) : close.insert(i);
  
  auto rev=[&](Int x){
    if(s[x] == '(') {
      A.add(x, n, -2);
      s[x] = ')';
      open.erase(x);
      close.insert(x);
    }
    else if(s[x] == ')') {
      A.add(x, n, +2);
      s[x] = '(';
      close.erase(x);
      open.insert(x);
    }
  };
  
  auto check =[&](Int x){
    rev(x);
    Int res = 1;
    if(A.find(0, n) < 0) res = 0;
    if(A.find(n-1, n) != 0) res = 0;
    rev(x);
    return res;
  };
    
  auto find=[&](set<Int> &par,Int R){
    
    Int L = -1;
    while(L+1<R){
      Int M = (L+R)/2;
      auto it = par.lower_bound(M);
      if(it == par.end()) {R = M;continue;}
      if(check(*it) == false) L = M;
      else R = M;
    }
    
    return *par.lower_bound(R);
  };

  srand((unsigned)time(NULL));
  for(Int i=0;i<q;i++){
    Int x;
    cin>>x; x--;
    rev(x);
    Int y;
    if(s[x] == ')') y = find(close,x);
    if(s[x] == '(') y = find(open,x);
    rev(y);
    //assert(valid(s));
    assert((Int)open.size() + (Int)close.size() == n);
    cout<<y+1<<endl;
  }
  return 0;
}

