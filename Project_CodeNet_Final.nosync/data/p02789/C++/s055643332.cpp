#include<bits/stdc++.h>
#define lli long long int
#define ulli unsigned long long int
#pragma GCC target ("sse4.2")
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define time cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";

int main()
{


    fast;

    lli n,m;
    cin>>n>>m;
    if(n<=m)
    {
        cout<<"Yes";
    }
    else
        cout<<"No";


    return 0;

}
