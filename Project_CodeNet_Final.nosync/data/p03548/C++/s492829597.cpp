#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<map>
#define ll long long
#define gc getchar()
using namespace std;
#define mem(a,b) memset(a,b,sizeof a)
#define upf(i,a,b) for(int i=a,i##e=b;i<=i##e;++i)
#define fup(i,a,b) for(int i=a,i##e=b;i<i##e;++i)
#define hh putchar(10)


class FIO
{
public:
	template<typename T>FIO& operator >>(T& x){ _R(x);return *this; }
	template<typename T>FIO& operator <<(T x){ _W(x);return *this; }
private:
	char f,c,a[26],i;
	template<typename T>inline void _R(T& x)
	{
		for(f=0;(c=getchar())<48;c==45&&(f=1));
		for(x=c^48;(c=getchar())>47;x=(x<<3)+(x<<1)+(c^48));
		if(f)x=-x;
	}
	template<typename T>inline void _W(T x)
	{
		if(sizeof(x)==1){ putchar(x);return; }
		if(x<0)putchar(45),x=-x;
		if(x>99) {
			for(i=0;x;x/=10)a[i++]=x%10;
			while(i--)putchar(a[i]+48);
		} else if(x>9)putchar(x/10+48),putchar(x%10+48);
		else putchar(x+48);
	}
}io;

char ch,fh;
template<class T>inline void zin(T& x) {
	for(fh=0;(ch=getchar())<48;ch==45&&(fh=1));
	for(x=ch^48;(ch=getchar())>47;)x=(x<<3)+(x<<1)+(ch^48);
	if(fh)x=-x;
} void qin(){}
template<class T,class...U>
void qin(T& head,U&...tail){zin(head);qin(tail...);}




int main()
{
	int x,y,z;
	io>>x>>y>>z;
	x-=z;
	io<<x/(y+z);
	return 0;
}
