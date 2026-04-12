#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi = 3.141592654;
//
//void solve()
//{
//    ll a[4][4],b[4][4];
//    for(int i=1; i<=2; i++)
//    {
//        for(int j=1; j<=2; j++)
//            cin>>a[i][j];
//    }
//    for(int i=1; i<=2; i++)
//    {
//        for(int j=1; j<=2; j++)
//            cin>>b[i][j];
//    }
//    ll a1,a2;
//
//    for(int i=1,k=2; i<=2; i++)
//    {
//        for(int j=1; j<=2; j++)
//        {
//            a1+=(a[i][j]*b[j][i]);
//            a2+=(a[i][j]*b[j][k]);
//        }
//
//        cout<<a1<<" "<<a2<<endl;
//    }
//
//
//}

void solve()
{
    ll n;
    cin>>n;
    ll arr[n+1];
    deque<ll>q;

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(i%2==0)
            q.push_back(arr[i]);
        else
            q.push_front(arr[i]);
    }
    if(n%2 !=0)
        reverse(q.begin(),q.end());
    for(int i=0;i<n;i++)
        cout<<q[i]<<" ";


}

int main()
{
    ios_base :: sync_with_stdio(false);
    ll t,i=1;
    //cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
}
