#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(){
  
  int sum=0;
  rep(i,3){
    sum*=10;
    int a;
    cin >> a;
    sum+=a;
  }
  if(sum%4==0) cout <<"YES"<<endl;
  else cout << "NO" << endl;
  
  return 0;
}