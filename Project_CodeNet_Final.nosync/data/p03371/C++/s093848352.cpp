#include<bits/stdc++.h>
using namespace std;
#define ll long long
int prime[100100];


int main()
{

int a,b,c,x,y;
cin >> a >> b >> c >> x >> y;

if(a >=c*2 && c*2<= b)
{
    int mx = max(x,y);
    c*=2;

    cout << (mx*c) << endl;
}
else if(a>=c*2 )
{
    c*=2;
    int baki = 0;
    if(y>x)baki = y-x;

    cout << x*c+baki*b << endl;


}
else if(b>=c*2)
{
    c*=2;
    int baki = 0;
    if(x>y)baki = x-y;

    cout << y*c+baki*a << endl;

}
else if(a+b>=c*2)
{

    int mn = min(x,y);

    if(x>mn)
    {
        int baki = x-mn;
        cout << (mn*c*2)+baki*a << endl;
    }
    else if(y>mn)
    {
           int baki = y-mn;
        cout << (mn*c*2)+baki*b << endl;
    }
    else
    {
        cout << mn*c*2 << endl;
    }

}
else
    cout << a*x+b*y<< endl;


}
