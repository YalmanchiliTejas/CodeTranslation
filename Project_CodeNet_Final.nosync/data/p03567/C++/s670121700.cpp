#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<vector>
#define rint register int
#define debug(x) cerr<<#x<<"="<<x<<endl
#define fgx cerr<<"-------------"<<endl
typedef long long ll;
using namespace std;
char c[100];
int main()
{	scanf("%s",c+1);
	int n=strlen(c+1);
	for(rint i=1;i<n;i++)
	if(c[i]=='A'&&c[i+1]=='C'){cout<<"Yes"<<endl;return 0;}
	cout<<"No"<<endl;
 	return 0;
}
