#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i<n; i++)


using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;


int main(){
  int n;
  cin >> n;
  vector<int> V(n);
  rep(i, n){
    cin >> V[i];
  }
  
  long long ans = 0;
  
  ll sum = 0;
  for(int j = 0; j<n; j++){
      sum += V[j];
  }
  
 
  
  for(int i = 0; i<n; i++){
    ll sum2;
    sum -= V[i];
    sum2 = sum;
    sum2 %= 1000000007;
    sum2 *= V[i];
    ans += sum2;
    ans %= 1000000007;
  }
      
     
  
  cout << ans << endl;
    

    
}

      
      
       



