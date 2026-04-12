#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main(){

ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,i,max=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    int count=1;
    max=a[0];
    for(i=1;i<n;i++)
    {
    	if(max<=a[i])
    	{
    		count++;
    		max=a[i];
		}
    
	}
	cout<<count;

}