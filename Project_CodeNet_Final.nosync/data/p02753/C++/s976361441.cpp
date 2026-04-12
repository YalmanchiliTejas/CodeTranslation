#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int read()
{
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
    return s*f;
}
int main()
{
    string s;
    while(cin>>s)
    {
        int a=0;
        int b=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='B')b++;
            else a++;
        }
        if(a!=0&&b!=0)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
