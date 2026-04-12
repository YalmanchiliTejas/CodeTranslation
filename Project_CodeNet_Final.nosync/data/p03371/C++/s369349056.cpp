#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() 
{  
    
    int arr[10];
    for(int i=0; i<3; i++)
    {
        cin>>arr[i];
    }
    ll x,y;
    cin>>x>>y;
    ll total=min(x,y);
    ll total1=max(x,y);
    ll mn3=(total1*2)*arr[2];
    ll xx=x;
    ll yy=y;
    xx-=total;
    yy-=total;
    ll mn1=(total*2)*arr[2];
    mn1+=(xx*arr[0])+(yy*arr[1]);
    ll mn2=(x*arr[0]+y*arr[1]);
    cout<<min({mn3,mn1,mn2})<<endl;
    

	return 0;
}