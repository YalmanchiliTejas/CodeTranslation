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



char mp[106][106],bookh[106],bookw[106];

int main()
{
	int h,w;
	io>>h>>w;
	fup(i,0,h)scanf("%s",mp[i]);
	for(int i=0,j;i<h;++i)
	{
		j=0;
		while(mp[i][j]=='.'&&j<w)++j;
		if(j==w)bookh[i]=1;
	}
	for(int i=0,j;i<w;++i)
	{
		j=0;
		while(mp[j][i]=='.'&&j<h)++j;
		if(j==h)bookw[i]=1;
	}
	/*
	for(int i=0;i<h;++i)printf("%d",bookh[i]);hh;
	for(int i=0;i<w;++i)printf("%d",bookw[i]);hh;
	*/
	fup(i,0,h) {
		if(bookh[i])continue;
		fup(j,0,w) {
			if(bookw[j])continue;
			putchar(mp[i][j]);
		}hh;
	}
	return 0;
}
