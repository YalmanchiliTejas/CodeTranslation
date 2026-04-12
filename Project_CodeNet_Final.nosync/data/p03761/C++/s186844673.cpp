#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
#include<math.h>
#include<assert.h>
// #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long int INFLL = 1001001001001001LL;
constexpr int INFI = 1000000007;
const int mod = 1000000007;

int main(){
  int n;
  cin >> n;
  vector<string> S(n);
  for(int i=0; i<n; i++){
    cin >> S[i];
  }
  int ans=0;
  sort(S[0].begin(),S[0].end());
  vector<bool> can_sum((int)S[0].size(),true);
  for(int i=1; i<n; i++){
    int j=0,k=0;
    sort(S[i].begin(),S[i].end());
    vector<bool> can((int)S[0].size(),false);
    while(j<(int)S[0].size() && k<(int)S[i].size()){
      if(S[0][j] == S[i][k]){
        can[j] = true;
        j++;
        k++;
      }else if(S[0][j]-'a' > S[i][k]-'a'){
        k++;
      }else{
        j++;
      }
    }
    for(int l=0; l<(int)S[0].size(); l++){
      if(!(can[l] && can_sum[l])){
        can_sum[l] = false;
      }
    }
  }
  for(int i=0; i<(int)S[0].size(); i++){
    if(can_sum[i]){
      cout << S[0][i];
    }
  }
  cout << endl;
  return 0;
}
