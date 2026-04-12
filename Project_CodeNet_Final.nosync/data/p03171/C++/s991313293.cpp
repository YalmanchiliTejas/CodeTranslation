#include <bits/stdc++.h>

using namespace std;

long long mem[3005][3005][2];
int n;
int arr[3005];

long long go(int x,int y,int p)
{
	if(x>y) return 0;
	if(mem[x][y][p]!=-1) return mem[x][y][p];
	if(p==0) return mem[x][y][p]=max(arr[x]+go(x+1,y,1),arr[y]+go(x,y-1,1));
	return mem[x][y][p]=min(go(x+1,y,0),go(x,y-1,0));
}

int main()
{
	cin >> n;
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		sum+=arr[i];
	}
	memset(mem,-1,sizeof mem);
	long long x=go(0,n-1,0);
	cout << x-(sum-x) << endl;
}