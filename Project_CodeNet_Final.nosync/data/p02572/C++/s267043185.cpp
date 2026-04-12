#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
long long int sum=0;
   cin>>n;
vector<long int> a(n);
for(int i=0;i<n;i++)
{
cin>>a[i];
sum+=a[i];
}


  long long int ans=0;
long long int mo=1000000007;
sum=sum;
for (int i = 0; i < n-1; i++)
{
sum-=a[i];
    ans+=(a[i]%mo)*(sum%mo);
ans=ans%mo;

}

cout<<ans<<endl;
}