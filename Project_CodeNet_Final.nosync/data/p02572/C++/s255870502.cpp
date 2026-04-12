#include<bits/stdc++.h>
using namespace std;
vector<long long int > fillPrefixSum(vector<long long int> v) 
{ 
   
   int n = v.size();
   vector<long long int> prefix(n);
    prefix[0] = v[0]; 
    int mod = 1e9+7;
    for (int i = 1; i < n; i++) 
        prefix[i] = (prefix[i - 1]%mod + v[i]%mod)%mod; 
  return prefix;  
} 
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<long long int> v(n);
    int mod = 1e9+7;
    for(long long int &x:v)
    {
		cin>>x;
	}
	//for(long long int x:v)cout<<x<<" ";
	//cout<<endl;
	reverse(v.begin(),v.end());
	//for(long long int x:v)cout<<x<<" ";
	//cout<<endl;
	vector<long long int> prefix = fillPrefixSum(v);
	//for(long long int x:prefix)cout<<x<<" ";
	//cout<<endl;
	reverse(v.begin(),v.end());
	//for(long long int x:v)cout<<x<<" ";
	//cout<<endl;
	reverse(prefix.begin(),prefix.end());
	//for(long long int x:prefix)cout<<x<<" ";
	//cout<<endl;
	long long int sum=0;
	for(int i=0;i<n-1;i++)
	{
		sum =( sum %mod + (v[i]%mod*prefix[i+1]%mod)%mod)%mod;
	}
	cout<<sum<<endl;
    return 0;
}
