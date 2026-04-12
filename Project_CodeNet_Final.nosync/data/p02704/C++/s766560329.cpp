#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
typedef unsigned long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }
// Container コンテナ型, map以外
template< template<class ...> class Ctn,class T>
std::ostream& operator<<(std::ostream& os,const Ctn<T>& v){
  // ここでストリームに obj を書き込みます。
  auto itr=v.begin();
  while(itr!=v.end()){
    if(itr!=v.begin())cout << " ";
    cout << *(itr++);
  }
  return os;
}

void input(vector<vector<int>>& v,int k,li a,int flag){
  rep(i,64){
    if(flag!=a%2){
      v[i][k]=2-flag;
    }
    a/=2;
  }
}

int calc(vector<vector<int>>& sgy,vector<int>& s,vector<int>& t,
         vector<int>& u,vector<int>& v){
  if(df) print(s,t,"u",u,"v",v);
  int f1=0,f2=0,f,g1=3,g2=3;
  for(int x:u){ f1|=x; g1&=x;}
  for(int x:v){ f2|=x; g2&=x;}
  f=f1*f2*(f1+f2);
  int n=s.size();
  if(g2){
    rep(i,n){
      if(((g2-1)^u[i]^(!!s[i]))==1)return 1;
    }
  }
  if(g1){
    rep(i,n){
      if(((g1-1)^v[i]^(!!t[i]))==1)return 1;
    }
  }
  if(df) print(f1,f2,f);
  if(f!=0 and f!=2 and f!=16) return 1;
  vector<int> unu,unv;
  rep(i,n){
    if(!u[i]) unu.push_back(i);
    rep(j,n) sgy[i][j]=u[i]-1;
  }
  rep(j,n){
    if(!v[j]) unv.push_back(j);
    rep(i,n) if(sgy[i][j]==-1) sgy[i][j]=v[j]-1;
  }
  
  if(df){
    rep(i,n) print(sgy[i]);
    print("u:",unu);
    print("v:",unv);
  }
  if(unu.size()*unv.size()==0) return 0;
  if(n==1){
    if(s[0]!=t[0])return 1;
    else sgy[0][0]=s[0];
    return 0;
  }
  if(unu.size()==1){
    int flag=1;
    int a=s[unu[0]];  // aがあればok
    rep(j,n) if(sgy[unu[0]][j]==a) flag=0;
    for(int j:unv){
      int b=t[j];    // bがあればok
      rep(i,n){
        if(i==unu[0])continue;
        // if(a==sgy[i][j]) flag=0;
        if(b==sgy[i][j]){
          sgy[unu[0]][j]=a;
          if(df)print("[",unu[0],j,"]=",a);
          flag=0;
          break;
        }
      }
      if(sgy[unu[0]][j]==-1) sgy[unu[0]][j]=b;
      if(sgy[unu[0]][j]==a) flag=0;
    }
    return flag;
  }
  
  
  if(unv.size()==1){
    int flag=1;
    int b=t[unv[0]];  // bがあればok
    rep(i,n) if(sgy[i][unv[0]]==b) flag=0;
    for(int i:unu){
      int a=s[i];    // aがあればok
      rep(j,n){
        if(j==unv[0])continue;
        //if(b==sgy[i][j]) flag=0;
        if(a==sgy[i][j]){
          sgy[i][unv[0]]=b;
          if(df)print("[",i,unv[0],"]=",b);
          break;
        }
      }
      if(sgy[i][unv[0]]==-1) sgy[i][unv[0]]=a;
      if(sgy[i][unv[0]]==b) flag=0;
    }
    return flag;
  }
  rep(i,unu.size())
    rep(j,unv.size())
    sgy[unu[i]][unv[j]]=(i+j)%2;
  return 0;
}


int main(){
  int n; cin >>n;
  vector<int> s(n),t(n);
  vector<vector<int>> u(64,vector<int>(n,0)),v(64,vector<int>(n,0));
  li dm=1;
  rep(i,n) cin >> s[i];
  rep(i,n) cin >> t[i];
  rep(i,n){
    li a; cin >>a; if(dm<a) dm=a;
    input(u,i,a,s[i]);
  }
  int ord=3; while(dm){ord++;dm/=2;}
  ord=min(64,ord); ord=64;
  rep(i,n){
    li a; cin >>a;
    input(v,i,a,t[i]);
  } 
  if(df){
    print(s,t);
    rep(i,ord) print(u[i]);
    rep(i,ord) print(v[i]);
  }

  vector<vector<li>> ans(n,vector<li> (n,0));
  vector<vector<int>> sgy(n,vector<int> (n,-1));
  
  li b=1;
  rep(i,ord){
    if(calc(sgy,s,t,u[i],v[i])){
      print(-1);
      return 0;
    }
    if(df) rep(i,n) print(sgy[i]);
    rep(row,n) rep(col,n) ans[row][col]+=sgy[row][col]*b;
    if(df) print("2^",i,"=",b);
    b*=2;
  }
  for(auto x:ans) print(x);
}
