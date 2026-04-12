#include <bits/stdc++.h> 

using namespace std; 
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>; 

#define INF 1000000000000000000
#define MOD 10007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()

int main(){
  int N;
  cin>>N;
  vector<int>H(N);
  for(int i=0;i<N;i++)cin>>H[i];

  int memo=H[0];
  int ans=1;
  for(int i=1;i<N;i++){
    if(memo<=H[i]){
      ans++;
      memo=H[i];
    }
  }
  cout<<ans<<endl;
  return 0;
}

