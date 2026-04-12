#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    string s;
    cin>>s;
    bool a = false, b = false;
    for(int i = 0; i < 3; i++){
        if(s[i] == 'A')
        a=true;
        else
        {
            b = true;
        }
        
    }
    if(a && b) cout<<"Yes";
    else cout<<"No";
    return 0;
}