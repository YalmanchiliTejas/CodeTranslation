#include<iostream>
using namespace std;
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>
#define int long long int
#define mod 1000000007
int power(int a,int b,int m)
{
	if(b==0)
	{
		return 1%m;
	}
	else
	{
		int r=power(a,b/2,m);
		if(b%2==0)
		{
			return (r*r)%m;
		}
		else
		{
			int x=(r*r)%m;
			return (a*x)%m;
		}
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,x;
	cin>>n>>x>>m;
	if(n<=m+10)
	{
		int arr[n];
		arr[0]=x;
		int j;
		for(j=1;j<n;j++)
		{
			int val=arr[j-1];
			int temp=power(val,2,m);
			arr[j]=temp;
		}
		int answer=0;
		for(j=0;j<n;j++)
		{
			answer+=arr[j];
		}
		cout<<answer<<endl;
		exit(0);
	}
	int value[m+5];
	bool visited[m+5]={false};
	int j;
	vector<int> vec;
	for(j=0;j<=m;j++)
	{
		int here;
		if(j==0)
		{
			vec.push_back(x);
			value[j]=x;
			here=x;
		}
		else
		{
			int val=value[j-1];
			int temp=power(val,2,m);
			value[j]=temp;
			vec.push_back(value[j]);
			here=value[j];
		}
		if(visited[here])
		{
			break;
		}
		visited[here]=true;
	}
	int y=vec.size();
	int val=vec[y-1];
	for(j=y-2;j>=0;j--)
	{
		if(vec[j]==val)
		{
			break;
		}
	}
	vec.pop_back();
	y=vec.size();
	vector<int> count(y,0);
	int i;
	for(i=j-1;i>=0;i--)
	{
		count[i]=1;
	}
	for(i=j;i<y;i++)
	{
		count[i]=1;
	}
	n-=y;
	int total=n/(y-j);
	for(i=j;i<y;i++)
	{
		count[i]+=total;
	}
	int left=n%(y-j);
	int ptr=j;
	while(left!=0)
	{
		count[ptr]++;
		ptr++;
		left--;
	}
	int answer=0;
	for(i=0;i<y;i++)
	{
		int here=vec[i]*count[i];
		answer+=here;
	}
	cout<<answer<<endl;
}
