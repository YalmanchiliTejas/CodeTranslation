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

int n;
string s;
int a[MAXN+1][27];

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        getline(cin,s);
        //for(int j=0;j<s.size();j++)a[i][s[j]-'a'+1]++;
        for(auto j:s)a[i][j-'a'+1]++;
    }
    for(int i=1;i<=26;i++)
    {
        int minn=233;
        for(int j=1;j<=n;j++)
        {
            minn=min(minn,a[j][i]);
            if(!minn)break;
        }
        for(int j=1;j<=minn;j++)putchar(i-1+'a');
    }
}