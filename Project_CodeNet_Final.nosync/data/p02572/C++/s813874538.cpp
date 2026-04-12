#include<bits/stdc++.h>
using namespace std;
#define mo 1000000007
int main(){   ios_base::sync_with_stdio(false);   cin.tie(0);     long long  n;   cin>>n;   long long a[n];   long long pro=0,sum=0,sum1=0;   for(long long i=0;i<n;++i){      cin>>a[i];      sum1+=a[i];      }   for(int i=0;i<n;++i){     pro+=a[i];   sum+=((a[i]%mo)*((sum1-pro)%mo))%mo;   sum%=mo;   }   cout<<sum;   return 0;   }