#include<iostream>
#include<algorithm>
using namespace std;
int a[200005];
const int mid=100002;
int main()
{
	int n;
	cin>>n;
	int front=0,back=1;
	for(int i=0;i<200005;i++)
	    a[i]=-1;
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
		{
			cin>>a[mid+front];
		    front++;
		}
		else
		{
			cin>>a[mid-back];
			back++;
		}    
	}
	int mark;
	for(int i=0;i<200005;i++)
	    if(a[i]!=-1)
	    {
	    	mark=i;
	    	break;
		}
	int c[n];
	int count=0;
	for(int i=mark;a[i]!=-1;i++)
	{
		c[count]=a[i];
		count++;
	}
	if(n%2==1)
	    reverse(c,c+n);
	for(int i=0;i<n;i++)
	    cout<<c[i]<<' ';
	return 0;
}