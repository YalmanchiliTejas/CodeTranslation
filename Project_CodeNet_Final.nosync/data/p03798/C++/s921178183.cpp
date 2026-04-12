#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    string s,smp[4]={"SS","SW","WS","WW"},ans="";
    cin >> n >> s;
    for(int i = 0;i < 4;i ++){
        string s0 = smp[i];
        for(int i = 1;i < n-1;i ++){
            bool issame;
            if((s0[i]=='S'&&s[i]=='o')||(s0[i]=='W'&&s[i]=='x')) issame=1;
            else issame=0;
            if(issame) s0 += s0[i-1];
            else s0 += s0[i-1]=='S'?'W':'S';
        }
        string smps = s;
        if(s0[0]=='W') smps[0] = smps[0]=='o'?'x':'o';
        if(s0[n-1]=='W') smps[n-1] = smps[n-1]=='o'?'x':'o';
        if(((smps[0]=='o'&&s0[1]==s0[n-1])||(smps[0]=='x'&&s0[1]!=s0[n-1]))&&
            ((smps[n-1]=='o'&&s0[0]==s0[n-2])||(smps[n-1]=='x'&&s0[0]!=s0[n-2]))){
                ans = s0;
                break;
            }
    }
    if(!ans.size()) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}