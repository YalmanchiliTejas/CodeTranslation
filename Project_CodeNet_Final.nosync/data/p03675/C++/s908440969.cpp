#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<set>
using namespace std;

const int maxn = 4200000;
int n;
int arr[maxn];

int main()
{
	while(cin >> n)
	{
		int rev = (n%2);
		if(rev == 0)
		{
			int pt = n/2;
			int step = 0;
			int r = 1;
			for(int i = 0;i<n;i++)
			{
				int x;
				scanf("%d",&x);
				arr[pt] = x;
				step ++;
				r = -r;
				pt += r*step;
			}
		}
		else 
		{
			int pt = n/2;
			int step = 0;
			int r = -1;
			for(int i = 0;i<n;i++)
			{
				int x;
				scanf("%d",&x);
				arr[pt] = x;
				step ++;
				r = -r;
				pt += r*step;
			}
		}
		for(int i = 0;i<n;i++)
		{
			if(i == 0) printf("%d",arr[i]);
			else printf(" %d",arr[i]);
		}
		cout<<endl;
		
	}
	return 0;
}