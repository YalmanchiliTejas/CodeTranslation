#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin>>s;
    bool ans=false;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]=='A' && s[i+1]=='C')ans=true;
    }
    if(ans)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}