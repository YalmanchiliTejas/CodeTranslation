#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define llu unsigned long long
#define U unsigned int
#define SIZE 1000002
#define pie 3.14159265358979323
#define minuss 1e-6
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    ll n;
    cin>>n;
    ll str[n+9];
    deque<ll>d;
    for(int i=0;i<n;i++)
    {
         cin>>str[i];
         if(i%2!=0)
            d.push_back(str[i]);
         else
            d.push_front(str[i]);
    }
    if(n%2==0)
        reverse(d.begin(),d.end());

    for(int i=0;i<d.size();i++)
        cout<<d[i]<<" ";

    cout<<endl;

}
