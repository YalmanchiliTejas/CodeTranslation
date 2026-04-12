#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const ll maxn=1e9+7;

int main(){
    int r,g,b;
    cin>>r>>g>>b;
    int x=r*100+g*10+b;
    if(x%4) cout<<"NO\n";
    else cout<<"YES\n";
    return 0;
}
