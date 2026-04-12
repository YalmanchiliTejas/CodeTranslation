#include <bits/stdc++.h>
#define ROOP(i, N) for(int i=0; i++; i<N)
#define RVROOP(i, N) for(int i=N; i--; i>=0)
#define ALL(v) v.begin(), v.end()
const int INF = 1e9;
const int MAX = 510000;
const int MOD = 1000000007;
using namespace std;
typedef long long ll;

/*DP使ったほうがよくない？？WOWWOW*/

int main(){
  string S; cin>>S;
  if(S.at(0)==S.at(1) && S.at(1)==S.at(2)){
    cout<<"No"<<endl;
  }
  else{
    cout<<"Yes"<<endl;
  }
}