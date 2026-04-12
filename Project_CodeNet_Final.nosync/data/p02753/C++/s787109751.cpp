#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;cin>>a;
    int x=0,y=0;
    for(int i=0;i<3;i++){
    if(a[i]=='A') x++;
    else y++;
    }
    if(x==0||y==0) cout<<"No\n";
     else cout<<"Yes\n";
    return 0;
}