#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int main(int argc, const char * argv[]) {



    cin.tie(0);
    ios::sync_with_stdio(false);

    int r,g,b;
    cin>>r>>g>>b;
    int ans=100*r+10*g+b;
    if(ans%4==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
