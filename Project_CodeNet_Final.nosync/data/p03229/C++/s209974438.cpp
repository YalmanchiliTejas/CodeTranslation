#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int num[100005];
int s[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
	cin>>num[i];
    }
    sort(num,num+n);
    int mid=n/2;
    long long sum=0;
    if(n%2==0)
    {
	for(int i=0;i<mid;i++)
	    sum-=2*num[i];
	for(int i=mid;i<n;i++)
	    sum+=2*num[i];
	sum=sum-num[mid]+num[mid-1];
    }
    else 
    {
	long long sum1=0;
	for(int i=0;i<mid;i++)
            sum1-=2*num[i];
        for(int i=mid;i<n;i++)
            sum1+=2*num[i];
        sum1=sum1-num[mid]-num[mid+1];
        for(int i=0;i<=mid;i++)
            sum-=2*num[i];
        for(int i=mid+1;i<n;i++)
            sum+=2*num[i];
        sum=sum+num[mid]+num[mid-1];
 	if(sum1>sum) sum=sum1;
    }
    cout<<sum<<endl;
}