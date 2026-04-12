#include<bits/stdc++.h>
using namespace std;
#define INF LONG_LONG_MAX
#define int long long
#define ar array
#define db double
#define pi 3.14159265358979323846
#define pow pw
int pw(int a,int b){
    int ans=1;
    while(b){
    if (b%2) ans*=a;
    a*=a;
    b/=2;
    }
    return(ans);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    if (n>=30) cout<<"Yes";
    else cout<<"No";
    return 0;
}