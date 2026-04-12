#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define newl '\n'




bool isprime(ll a)
{
    if(a<=1)
        return false;
    if(a==2||a==3)
        return true;
    if(a%2==0||a%3==0)
        return false;
    for(ll i=5;i*i<=a;i=i+6)
    {
        if(a%i==0||a%(i+2)==0)
            return false;
    }
    return true;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    if(t>=30)
    cout<<"Yes";
    else
    {
        cout<<"No";
    }
    

    return 0;
}
