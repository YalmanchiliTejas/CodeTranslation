#include<bits/stdc++.h>
using namespace std;
#define test int t;cin>>t;while(t--)
void fastcode()
{
    /*
    cout<<fixed<<setprecision(2);
    π = 3.141592653;
    itoa to convert any system itoa(n,bin,2)
    */
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main()
{
    /*freopen(" ","r",stdin);
    freopen(" ","w",stdout);*/
    fastcode();
    int n;
    cin>>n;
    if(n<30)
    {
        cout<<"No";
    }
    else
    {
        cout<<"Yes";
    }
    return 0;
}
