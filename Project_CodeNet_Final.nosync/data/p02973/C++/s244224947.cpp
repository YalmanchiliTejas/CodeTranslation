#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define Mabs(a,b) ((a)>(b)?(a)-(b):(b)-(a))
#define Abs(a) (a)>0?(a):(-(a))
template <typename QvQ> inline QvQ Min2(QvQ a,QvQ b){if(a<b) return a;return b;}
template <typename QvQ> inline QvQ Max2(QvQ a,QvQ b){if(a>b) return a;return b;}
template <typename QvQ> inline QvQ Abs2(QvQ a){if(a>0) return a;return -a;}

#define n1kw 10000000
#define inf 0x7f7f7f7f
#define dinf 0x3f3f3f3f
#define llinf 0x7f7f7f7f7f7f7f7f
#define lldinf 0x3f3f3f3f3f3f3f3f

#define ll long long
#define rei register int
#define inv inline void
#define inb inline bool
#define ini inline int

#define bl putchar(' ')
#define ed putchar('\n')
#define test std::cout<<"this:"
#define card system("pause")

#define read2(a,b) read(a),read(b)
#define write2(a,b) write(a),bl,write(b)
#define read3(a,b,c) read(a),read(b),read(c)
#define write3(a,b,c) write(a),bl,write(b),bl,write(c)

//char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)

template <typename QvQ>inv read(QvQ &x)
{
    x=0;int f=1;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
    for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    x=x*f;
}
template <typename QvQ>inv write(QvQ x)
{
    if(x<0) x=-x,putchar('-');
    if(x>9) write(x/10);
    putchar(x%10+48);
}
using namespace std;
int n,a[100005],dqd;
priority_queue <int> q[100005];
int main()
{
    read(n);
    for(rei i=1;i<=n;++i) read(a[i]);
    q[++dqd].push(a[1]);
    for(rei i=2;i<=n;++i)
    {
    	if(a[i]<=q[dqd].top()) q[++dqd].push(a[i]);
    	else
    	{
    		int l=1,r=dqd,pos;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(a[i]>q[mid].top()) pos=mid,r=mid-1;
				else l=mid+1;
			}
			q[pos].push(a[i]);
    	}
    }
    write(dqd);
    return 0;
}