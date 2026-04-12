#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin>>n;
  vector<int64_t>vec(n);
  for(int i=0;i<n;i++){
    cin>>vec.at(i);
  }
  int64_t sum=0,p=0;
  for(int i=0;i<n-1;i++){
    p=(p+vec.at(n-1-i))%1000000007;
    sum+=(vec.at(n-2-i)*p)%1000000007;
    }
  
  cout<<sum%1000000007<<endl;
}