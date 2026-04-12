#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  long long n,k,i,res=0;
  cin >> n >> k;
  if(k==0){
    cout << n*n << endl;
    return 0;
  }
  for(i=k+1;i<=n;i++)
    res+=n/i*(i-k)+max(n%i-k+1,(long long)0);
  cout << res << endl;
  return 0;
}