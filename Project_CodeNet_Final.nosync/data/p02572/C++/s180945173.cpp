#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<long long>a(n);
  long long sum1=0;
  for (int i=0;i<n;i++) {
    cin >> a.at(i); 
    sum1+=a.at(i);
  }
  sum1%=1000000007;
  long long ans=0;
  for (int i=0;i<n-1;i++) {
    sum1-=a.at(i);
    if(sum1<0){
    sum1+=1000000007;
    }
    ans+=(a.at(i)*sum1)%1000000007;
    ans%=1000000007;
  }
  cout << ans << endl;
}