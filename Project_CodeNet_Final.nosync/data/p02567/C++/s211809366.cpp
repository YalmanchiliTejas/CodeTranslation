#include<iostream>
#include<functional>
#include<atcoder/all>
using namespace std;
typedef long long li;
#define M_MAX 1000000001
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

struct mono{
  li ma,mi;
  mono(li a=-1,li b=M_MAX){ma=a,mi=b;};
};

mono e(){
  return mono();
}

mono op(mono m,mono n){
  return {max(m.ma,n.ma),min(n.mi,n.mi)};
}
// pair 型
std::ostream& operator<<(std::ostream& os, const mono& p){
  cout << "(" << p.ma << "," << p.mi << ")";
  return os;
}


int main(){
  int n,q; cin >>n >>q;
  vector<mono> v(n);
  rep(i,n){
    li a; cin >>a;
    v[i]={a,a};
  }
  atcoder::segtree<mono,op,e> sgt(v);
  if(df) rep(i,n)print(sgt.get(i));
  
  
  rep(_,q){
    int t; cin >>t;
    if(t==1){
      int x;li v; cin >>x >>v; x--;
      if(df)print(x,v);
      sgt.set(x,v);
    }else if(t==2){
      int l,r; cin >>l >>r;l--;
      mono p=sgt.prod(l,r);
      print(p.ma);
    }else{
      int x;li v; cin >>x >>v; x--;
      auto f=
        [&](mono p){
          return p.ma<v;
        };
      print(sgt.max_right<decltype(f)>(x,f)+1);
    }
  }
  
}
