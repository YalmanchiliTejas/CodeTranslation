#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const int M = 1e9 + 7;

int main()
{
 int n;
 cin>>n;
 int arr[n];
 for(int i=0; i<n; i++)
    cin>>arr[i];
 ll sum = 0, ans = 0;
 for(int i=0; i<n; i++){
    ans = (ans + (sum*arr[i])%M)%M;
    sum = (sum + arr[i])%M;
 }
 cout<<ans;
 return 0;
}

