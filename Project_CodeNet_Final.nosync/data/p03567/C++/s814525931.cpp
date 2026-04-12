#include <bits/stdc++.h>
using namespace std;
int got = 0;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    for(int i = 0; i < s.length()-1; i++){
        if(s[i]=='A' && s[i+1] == 'C'){
            cout<<"Yes";
            got = 1;
            break;
        }
    }
    if(!got)cout<<"No";
    return 0;
}
