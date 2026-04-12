#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
int main()
{
    int n;
    cin>>n;
    long a[n];
    for(int i = 0; i<n; i++)
        cin>>a[i];
    int ssum[n];
    ssum[n-1] = a[n-1];
    for(int i = n-2; i>=0; i--)
        ssum[i] = (a[i] + ssum[i+1])%M;
    long long int sum = 0;
    for(int i  = 0; i<n-1; i++)
        sum = (sum + (a[i]*ssum[i+1])%M)%M;
    cout<<sum<<endl;
    
        
    
}