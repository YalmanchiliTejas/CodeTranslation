#include <iostream>
#include <vector>
#include <list>
#include<utility>
#include <new>
#include <string>
#include<cmath>
#include<unordered_set>
#include<iomanip>
#include <stack>
#include<queue>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define loop(i,x,z) for (int i=x;i<z;i++)
using ll =  long long int;
#define mod 1000000007
/*bool cmp(pair<ll,ll>a,pair<ll,ll>b){
return a.second<b.second;
}*/
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    loop(i,0,n){
    cin>>a[i];
    }
    long long ans=0;
    vector<int>dp(n,0);
    dp[n-1]=a[n-1];
    for(int i=n-2;i>=1;i--){
        dp[i]=dp[i+1]+a[i];
        dp[i]=dp[i]%mod;
    }
    loop(i,0,n-1){
            ans+=(ll)a[i]*dp[i+1];
            ans=ans%mod;
        }
cout<<ans;
	return 0;
}
