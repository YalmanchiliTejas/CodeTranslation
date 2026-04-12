#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<utility>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) std::cout<<arg<<"\n"
#define prin2(arg1,arg2) std::cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) std::memset(arg,n,sizeof(arg))
using std::cin;
typedef long long ll;
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
const int INF=1e+9;
const ll INFLL=1e+17;
int N;
std::string s;
char d[100010];
//di,di-1,siからdi+1を求める
char next(char d1,char d2,char s1){
  if(d1==d2){
    if(s1=='o') return 'S';
    else return 'W';
  }
  else{
    if(s1=='o') return 'W';
    else return 'S';
  }
}

void solve(){
  d[0]='S';d[1]='S';
  rep1(i,N-1){
    d[i+1]=next(d[i],d[i-1],s[i]);
  }
  if(d[0]==d[N]&&next(d[0],d[N-1],s[0])==d[1]){
    rep(i,N) std::cout<<d[i];
    std::cout<<"\n";
    return ;
  }
  d[0]='S';d[1]='W';
  rep1(i,N-1){
    d[i+1]=next(d[i],d[i-1],s[i]);
  }
  if(d[0]==d[N]&&next(d[0],d[N-1],s[0])==d[1]){
    rep(i,N) std::cout<<d[i];
    std::cout<<"\n";
    return ;
  }
  d[0]='W';d[1]='S';
  rep1(i,N-1){
    d[i+1]=next(d[i],d[i-1],s[i]);
  }
  if(d[0]==d[N]&&next(d[0],d[N-1],s[0])==d[1]){
    rep(i,N) std::cout<<d[i];
    std::cout<<"\n";
    return ;
  }
  d[0]='W';d[1]='W';
  rep1(i,N-1){
    d[i+1]=next(d[i],d[i-1],s[i]);
  }
  if(d[0]==d[N]&&next(d[0],d[N-1],s[0])==d[1]){
    rep(i,N) std::cout<<d[i];
    std::cout<<"\n";
    return ;
  }  
  prin(-1);
  return ;
}
int main(){
  cin>>N;
  cin>>s;
  solve();
  return 0;
}
