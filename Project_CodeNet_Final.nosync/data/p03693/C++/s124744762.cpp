#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<queue>
#include<cstring>
#include<utility>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<bitset>
#include<deque>
#include<cctype>
using namespace std;
int main() 
{
	int r,g,b;
	scanf("%d %d %d",&r,&g,&b);
	if((g*10+b)%4==0)
	{
		cout<<"YES";
	}
	else
	cout<<"NO"; 
	return 0; 
}
    