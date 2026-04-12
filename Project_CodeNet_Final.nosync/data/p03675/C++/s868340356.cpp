#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<cstdlib>

#define REP(i,n) for(int i = 0;i < n;i++)

typedef long long ll;

using namespace std;

vector<int> b;
int a[300100];
int n; 
 
int main()
{
	cin >> n;
	REP(i,n) scanf("%d",&a[i]);
	
	if(n % 2 == 0)
	{
		for(int i = n-1;i > 0;i -=2)
			printf("%d ",a[i]);
		for(int i = 0;i < n;i += 2)
			printf("%d ",a[i]);
	}
	else
	{
		for(int i = n-1;i >= 0;i -= 2)
			printf("%d ",a[i]);
		for(int i = 1;i < n ;i += 2)
			printf("%d ",a[i]);
	}
	
	cout << endl;
	
	return 0;
}