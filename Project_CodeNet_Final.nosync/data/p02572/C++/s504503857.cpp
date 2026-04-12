#include<bits/stdc++.h>
using namespace std;
#define max 

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }

  	unsigned long long int pre[n];
  	pre[n-1]=a[n-1];
  	for(int i=n-2;i>0;i--)
  	{
  			pre[i]=(pre[i+1]%1000000007+a[i]%1000000007)%1000000007;
  			
  	}
  	int sum=0;
  	for(int i=0;i<n-1;i++)
  	{
  		//cout<<pre[i+1]<<" ";
  		sum=(sum%1000000007+((a[i])*(pre[i+1]))%1000000007)%1000000007;
  		//cout<<sum<<endl;
  	}
  	cout<<sum<<endl;

}