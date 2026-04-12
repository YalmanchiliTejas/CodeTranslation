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
#define fill(arg,n) memset(arg,n,sizeof(arg))
using std::cin;
typedef long long ll;
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
const int INF=1e+9;
const ll INFLL=1e+17;
int n;
std::string S[51];
int num[51][26];
void solve(){
  fill(num,0);
  rep(i,n){
    int ss=S[i].size();
    rep(j,ss){
      num[i][(int)(S[i][j]-'a')]++;
    }
  }
  int res[26];
  rep(j,26){
    int min=INF;
    rep(i,n){
      min=std::min(min,num[i][j]);
    }
    res[j]=min;
  }
  //  rep(i,26){
  //    std::cout<<res[i];
  //  }
  rep(i,26){
    rep(j,res[i]){
      std::cout<<(char)(i+'a');
    }
  }
  std::cout<<"\n";
}
int main(){
  cin>>n;
  rep(i,n) cin>>S[i];
  solve();
  return 0;
}
