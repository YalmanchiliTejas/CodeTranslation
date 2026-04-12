#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  long long int n, sum=0;	cin>>n;
  vector<long long int> A(n, 0);
  vector<long long int> B(n, 0);
  
  for(long long int i=0; i<n; i++)	
  {
    cin>>A[i];
    B[i]=A[i];
    sum += A[i];
  }
  
  for(long long int i=1; i<n; i++)	A[i] += A[i-1];
    
  long long int ans=0;
  for(long long int i=0; i<n; i++)
  {
    ans = (ans + B[i]*((sum-A[i])%1000000007)%1000000007)%1000000007;
  }
  
  cout<<ans;  
}