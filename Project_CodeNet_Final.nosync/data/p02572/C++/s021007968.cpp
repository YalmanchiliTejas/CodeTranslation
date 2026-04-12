#include<bits/stdc++.h>
using namespace std;
const int inf= 1e9+7;

int main(){
  int n;
  scanf("%d",&n);
  long long int arr[n];
  for(int a=0;a<n;a++)
    scanf("%lld", &arr[a]);
  long long int prefix[n];
  prefix[0]=arr[0];
  for(int a=1;a<n;a++)
  prefix[a]=(prefix[a-1]+arr[a])%inf;
  long long int ans=0;
  for(int a=0;a<n;a++)
  ans=(ans+arr[a]*(prefix[n-1]-prefix[a])+inf)%inf;
  printf("%lld", ans);
}