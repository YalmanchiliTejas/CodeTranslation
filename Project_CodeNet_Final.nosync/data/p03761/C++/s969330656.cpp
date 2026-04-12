#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

int read()
{
    char c=getchar();
    int d=0;
    while(c<'0' || c>'9')c=getchar();
    while(c>='0' && c<='9'){d=(d<<3)+(d<<1)+(c^48);c=getchar();}
    return d;
}

#define MAXN 50
#define INF 10086

int n;
string s;
int a[27];
int minn[MAXN+1];

int main()
{
    n=read();
	for(int i=1;i<=26;i++)minn[i]=INF;
    for(int i=1;i<=n;i++)
    {
		for(int j=1;j<=26;j++)a[j]=0;
        getline(cin,s);
        //for(auto j:s)a[j-'a'+1]++;
        for(char j:s)a[j-'a'+1]++;
		for(int j=1;j<=26;j++)minn[j]=min(minn[j],a[j]);
    }
    for(int i=1;i<=26;i++)
		for(int j=1;j<=minn[i];j++)putchar('a'+i-1);
}