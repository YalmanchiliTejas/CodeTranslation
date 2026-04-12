#include <bits/stdc++.h>
using namespace std;
int a,b,c;
void nhap()
{
    scanf("%d%d%d",&a,&b,&c);
}
void solve()
{
    int s = a*100+b*10+c;
    if (s%4==0)
    {
        cout<<"YES"<<endl;
    }
    else {cout<<"NO"<<endl;}
}
int main()
{
    nhap();
    solve();
    return 0;
}
