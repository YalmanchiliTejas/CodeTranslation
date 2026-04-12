#include<iostream>
#include<algorithm>
using namespace std;
int p=1e9+7;
typedef long long ll;
int main()
{
  ll n,a,s=0,i,res=0;
  cin >> n;
  for(i=0;i<n;i++){
    cin >> a;
    res+=(a*s)%p;
    res%=p;
    s+=a;
    s%=p;
  }
  cout << res << endl;
  return 0;
}
