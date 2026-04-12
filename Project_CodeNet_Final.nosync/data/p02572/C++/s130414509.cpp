#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
	int n;
  cin>>n;
  lli a=0, b=0;
  lli c;
  for(int i=0;i<n;i++){
  	cin>>c;
    a += c;
    a %= 1000000007;
    b += c*c;
    b %= 1000000007;
  }
  cout<<((a*a - b)%1000000007)*(500000004) % 1000000007;
  return 0;
}
