#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) cout<<arg<<"\n"
#define prin2(arg1,arg2) cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) memset(arg,n,sizeof(arg))
#define mp make_pair
#define pb push_back
#define BE begin()
#define EN end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef set<int> si;
typedef multiset<int> msi;
typedef string str;
const int INF=1e+9;
const ll INFLL=1e+17;
const ll MOD=1e+9+7;
int N;
int A[100010];
msi s;
int solve(){
  rep(i,N){
    auto itr=s.lower_bound(A[i]);
    if(itr==s.BE){
      s.insert(A[i]);
    }
    else{
      s.erase(--itr);
      s.insert(A[i]);
    }
  }
  return s.size();
}
int main(){
  cin>>N;
  rep(i,N) cin>>A[i];
  prin(solve());
  //  for(auto itr=s.begin();itr!=s.end();itr++){
  //    prin(*itr);
  //  }
  return 0;
}
