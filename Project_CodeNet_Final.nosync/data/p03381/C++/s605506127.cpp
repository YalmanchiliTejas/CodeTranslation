/*
problem's name:
statue:
writer:Patrick_y
*/
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
#include <stack>
#include <set>
#include <deque>
#include <cctype>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <time.h>
#define mp make_pair
typedef long long ll;
using namespace std;
const int INF=20050208;
/*------------main part------------*/



int a[200005];
int b[200005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	int m=n/2;
	for(int i=1;i<=n;i++)
	{
		if(b[i]<=a[m])
		{
			cout<<a[m+1]<<endl;
		}
		else
		{
			cout<<a[m]<<endl;
		}
	}
	return 0;
}
