#include<bits/stdc++.h>
using namespace std;

using ll=long long;



void solve(){
    string s;
    cin>>s;
    for(int i=0; i<s.size()-1; i++){
        if(s[i]=='A'&&s[i+1]=='C'){
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
}

signed main(){
    //while(1)
    solve();
}