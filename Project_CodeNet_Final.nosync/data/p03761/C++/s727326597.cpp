#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main() {
    long test=1;
    // cin>>test;
    while(test--)
    {
	long long t,i,j,n,a,b,c,d,ans,A,B,x,y,k,one,q,l,r;
	string s,s1,s2,s3;
	cin>>n;
	int arr[125]={0},brr[125]={0};
	cin>>s;
	    for(j=0;j<s.length();j++)
	        arr[s[j]]++;
	
	for(i=1;i<n;i++)
	{
	    cin>>s;
	    for(j=0;j<s.length();j++)
	        brr[s[j]]++;
	    for(k=0;k<125;k++)
	    {
	        arr[k]=min(arr[k],brr[k]);
	    }
	    for(k=0;k<125;k++)
	    {
	        brr[k]=0;
	    }

	}
	for(i=0;i<124;i++)
	{
	    cout<<string(arr[i],char(i));
	   //cout<<arr[i];
	}
	
	
    }

}