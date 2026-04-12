//Created by Aashray Agarwal urf maniAC
/*MY ATTITUDE ISN'T BAD,IT'S IN BETA.

YOU BETTER BE NICE TO ME,I COULD BE YOUR BOSS IN A FEW YEARS.

I TURN COFFEE INTO CODE,JUST BE ABLE TO AFFORD MORE COFFEE.*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll k,a,b;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll inc,ans;
    cin>>k>>a>>b;
    k-=a;
    ans=1;
    inc=a-b;
    if(k<=0)
    cout<<"1\n";
    else if(inc<=0)
    cout<<"-1\n";
    else
    {
        ans+=2*(k/inc);
        if(k%inc!=0)
        ans+=2;
        cout<<ans<<"\n";
    }
    return 0;
}