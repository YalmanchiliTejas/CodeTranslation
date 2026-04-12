#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod = 1000000007;
const double PI = 3.141592653589793238463;
const int N=1e5+9;
int main()
{
    FASTINOUT;
    int x;
    cin>>x;
    int ans=1,mx=0,y;
    cin>>y;
    mx=y;
    for (int i=1;i<x;i++){
        cin>>y;
        if (y>=mx)
        {
            ans++;
            mx=y;
        }
    }
    cout<<ans<<endl;
    return 0;
}
