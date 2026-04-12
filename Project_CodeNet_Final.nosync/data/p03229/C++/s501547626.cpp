#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
int N_MAX = 200000;
int main()
{
  int n;
  cin >> n;
  int a[N_MAX];
  for(int i=0;i<n;i++)
    cin >> a[i];
  sort(a,a+n);
  int m;
  long long sum = 0;
  if(n%2==1){
    m = (n-1)/2;
    for(int i=1;i<=m;i++)
      sum += 2*i*(long long)(a[i]-a[i-1]+a[n-i]-a[n-i-1]);
    sum -= min(a[m]-a[m-1],a[m+1]-a[m]);
  } else {
    m = n/2-1;
    for(int i=1;i<=m;i++)
      sum += 2*i*(long long)(a[i]-a[i-1]+a[n-i]-a[n-i-1]);
    sum += (2*m+1)*(long long)(a[m+1]-a[m]);
  }
  cout << sum << endl;
  return 0;
}