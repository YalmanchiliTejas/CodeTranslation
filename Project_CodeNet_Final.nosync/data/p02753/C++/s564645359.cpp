#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#define lowbit(x) ((-x)&(x))
#define f(i,x,y) for(int i=(x);i<=(y);i++)
#define r(i,x,y) for(int i=(x);i>=(y);i--)
#define ll long long
using namespace std;//head
const int inf=0x3f3f3f3f;
string s; 
int main(){
cin>>s;
int a=0,b=0;
for(int i=0;i<s.length();i++ ){
	if(s[i]=='A')a++;
	else b++; 
}
if(a&&b)printf("Yes");
else printf("No");
	
	return 0;
}
