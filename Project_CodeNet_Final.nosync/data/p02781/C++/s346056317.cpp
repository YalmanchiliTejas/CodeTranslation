#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string s;
int K;

  long long com(long long N, long long R) {
    if (R < 0 || R > N) return 0;
    if (R == 1) return N;
    else if (R == 2) return N * (N-1) / 2;
    else return N * (N-1) * (N-2) / 6;
}

long long pow(long long N, long long k) {
    long long res = 1;
    for (int i = 0; i < k; ++i) res *= N;
    return res;
}

long long dfs(int i, int k, int flag){
  if(i == n){
    if(k==0) return 1;
    else return 0;
  }
  if(k==0) return 1;
  
  if(flag)  return com(n-i,k)*pow(9,k);
          
  
  else{
    if(s[i] == '0') return dfs(i+1,k,0);
    
    else{
      long long int ans1 = dfs(i+1,k,1);
      long long int ans2 = dfs(i+1,k-1,1)*((s[i]-'0')-1);
      long long int ans3 = dfs(i+1,k-1,0);
    
      return ans1 + ans2 + ans3;
    }
  }
  }

  
int main(){
  cin >> s ;
  cin >> K;
  n=s.size();
  
  
  cout << dfs(0,K,0) << endl;
}
