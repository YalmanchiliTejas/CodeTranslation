#include<iostream>
#include<string>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define EACH(x,a) for(auto& (x):(a))
#define ALL(obj) (obj).begin(),(obj).end()
#define Yes(n) cout<<((n)?"Yes":"No")<<endl;
using namespace std;
using ll=long long;
const int INF=1e9;
const ll LINF=1e18;
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  string S;
  int K;
  cin>>N;
  cin>>S;
  cin>>K;

  char s = S[K-1];
  REP(i,S.length()){
    if(S[i]!=s) S[i]='*';
  }

  cout<<S<<endl;
  return 0;
}