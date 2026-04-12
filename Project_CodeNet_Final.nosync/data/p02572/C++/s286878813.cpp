#include <bits/stdc++.h>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    int m=1000000007;
    int n;cin>>n;
    long long int sum=0;
    long long int A[n];
    long long int ans=0;
    for(int i=0;i<n;i++){
    	long long int x;
    	cin>>x;
    	x=x%m;
    	long long int p=(sum*x)%m;
    	ans=(ans+p)%m;
    	sum=(sum+x)%m;
	}
	cout<<ans;
    
return 0;
}
