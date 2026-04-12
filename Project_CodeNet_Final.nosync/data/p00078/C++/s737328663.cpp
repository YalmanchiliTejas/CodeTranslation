#include <iostream>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long

int main()
{
    int n;
    while(1)
    {
	cin >> n;
	if (n==0)break;
	int t[15][15]={0};
	int x=n/2,y=n/2+1;
	rep(i,n*n)
	{
	    if (t[y][x] == 0)
	    {
		t[y][x]=i+1;
		x=(x+1)%n;
		y=(y+1)%n;
	    } else {
		x=(x-1+n)%n;
		y=(y+1)%n;
		i--;
	    }
	}
	rep(i,n)
	{
	    rep(j,n)
	    {
		printf("%4d",t[i][j]);
	    }
	    printf("\n");
	}
    }
    return 0;
}