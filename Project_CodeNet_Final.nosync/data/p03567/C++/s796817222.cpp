#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
inline void read(int &x)
{
	x=0;
	int p=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')p=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^'0');c=getchar();}
	x*=p;
}
string s;
int main()
{
	cin>>s;
	for(int i=0;i<s.size()-1;i++)if(s[i]=='A'&&s[i+1]=='C')return puts("Yes"),0;
	puts("No");
	return 0;
}