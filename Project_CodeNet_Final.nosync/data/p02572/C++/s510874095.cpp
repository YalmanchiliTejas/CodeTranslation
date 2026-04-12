#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;
 
  vector<long long> a(N);
  for(int i=0;i<N;i++){
    cin >> a.at(i);
  }
  
  sort(a.begin(),a.end());
  
  long long sum=0;
  long long ans=0;
  for(int i=0;i<N-1;i++){
    long long neko=0;
    sum = sum + a.at(i);
    sum = sum %1000000007;
    neko = (sum * a.at(i+1))%1000000007;
    ans = ans + neko;
    ans = ans%1000000007;
  }
  
  cout << ans << endl;
  
  
}