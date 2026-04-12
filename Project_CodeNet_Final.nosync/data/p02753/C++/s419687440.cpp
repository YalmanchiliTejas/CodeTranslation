 #include <bits/stdc++.h>
using namespace std;

int n,m;

inline int qr()
{
    int s=0,f=1;char ch=0;
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
    return s*f;
}

int main()
{
    char a,b,c;
    cin>>a>>b>>c;
    if(a==b&&b==c)
    	cout<<"No"<<endl;
    else
    	cout<<"Yes"<<endl;
    return 0;
}