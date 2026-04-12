#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000007 // 10^9+7
string s;
bool ans=false;
signed main(){
    cin>>s;
    int l=s.size();
    rep(i,l-1){
        if(s.substr(i,2)=="AC")ans=true;
    }
    if(ans)puts("Yes");
    else puts("No");
    return 0;
}