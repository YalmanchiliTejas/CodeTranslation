#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005

using namespace std;

int A[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		int to;
		if(i%2==(n-1)%2)
		{
			to=i+(n-i-1)/2;
		}
		else
		{
			to=(n-i)/2-1;
		}
		A[n-to-1]=a;
	}
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",A[i]);
	}puts("");
	return 0;
}
