#include<bits/stdc++.h>
#define LL long long
#define max 1e5

using namespace std;

int gcd(int a , int b)
{
        return a%b==0? b:gcd(b,a%b);
}
inline int quickread()
{
	int X=0; bool flag=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') flag=0; ch=getchar();}
	while(ch>='0'&&ch<='9') {X=(X<<1)+(X<<3)+ch-'0'; ch=getchar();}
	if(flag) return X;
	return ~(X-1);
}
void slove()
{
    ;
}
int main()
{
    /*int t;
    cin>>t;
    while(t--)
    {
        slove();
    }*/
    int t;
    cin>>t;
    if(t>=30)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
