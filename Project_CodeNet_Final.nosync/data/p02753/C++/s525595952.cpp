#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#define X first
#define Y second
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int N=1000010,mod=1e9+7; 

string s;
int a,b;

int main()
{
	cin>>s;
	
	for(int i=0;i<3;i++)
		if(s[i]=='A') a++;
		else b++;
	
	if(a&&b) puts("Yes");
	else puts("No");
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}







