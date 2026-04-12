#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
inline int rd(){
	int res=0,sign=1;char ch;
	while((ch=getchar())<'0'||ch>'9')if(ch=='-')sign=-1;res=res*10+ch-48;
	while((ch=getchar())>='0'&&ch<='9')res=res*10+ch-48;
	return res*sign;
}
int n;
int main(){
	cin>>n;
	cout<<n*800-(n/15)*200<<endl;
	return 0;
}
