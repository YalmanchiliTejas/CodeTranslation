#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 1000000000000
#define MOD 1000000007
using ll = long long;

//next_permutation
int main(){
  int n,m;
  cin >> n >> m;
  vector<int> A(m),B(m);
  rep(i,m)cin >> A.at(i) >> B.at(i);
  vector<set<int>> AL(n);
  rep(i,m){
    AL.at(A.at(i)-1).insert(B.at(i));
    AL.at(B.at(i)-1).insert(A.at(i));
  }

  vector<int> v(n);
  int ans = 0;
  rep(i,n)v.at(i)=i;//z_index
  do{
    if(v.at(0)!=0)break;
    int flag = 0;
    for(int i = 0; i < n-1; i++){
      if(!AL.at(v.at(i)).count(v.at(i+1)+1))flag=1;
    }
    if(flag)continue;
    else ans++;
  }while(next_permutation(v.begin(),v.end()));
  cout<<ans<<endl;
  return 0;
}