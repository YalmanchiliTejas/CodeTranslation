#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x)
{
	x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
}
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	x*=f;
	return;
}	
template<typename T>
void write(T x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
	return;
}
string s;
int main()
{
	cin>>s;
	if(s=="AAA"||s=="BBB") cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;
}
