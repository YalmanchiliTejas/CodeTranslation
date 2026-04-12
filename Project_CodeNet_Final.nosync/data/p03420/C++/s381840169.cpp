#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ll long long
const int MX=200000;
int N, M, k, x;
int arr[MX];
int main()
{
   /// for(int i=0;i<20;i++) cout<<i%4<<" ";
    ll n, k, an=0;
    cin>>n>>k;
    for(ll b=k+1;b<=n;b++)
    {
        ll d=n/b;
        an+=d*max(0LL, b-k);
        d=n%b;
        an+=max(0LL, d-k+1);
    }
    if(!k) an=n*n;
    cout<<an<<'\n';
}
