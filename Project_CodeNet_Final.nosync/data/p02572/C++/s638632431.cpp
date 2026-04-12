#include <iostream>
using namespace std;

int main() {
    unsigned long long int a[200000], sum = 0, n, mod = 1000000007, s = 0;
    cin>>n;
    for (int i = 0; i<n; i++)
    {    cin>>a[i];		s += a[i];	}
    for (int i = 0; i <n; i++)
    {
      s -= a[i];	
      sum = (sum + ((a[i]%mod) * (s%mod))) % mod;
    }
    cout<<sum<<endl;
    return 0;
}