#include <bits/stdc++.h>

using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s,t="qwertasdfgzxcvb";

    while(1){
        cin>>s;

        if(s=="#")break;

        int ans=0;
        bool p=true;//右ならtrue

        for(int i=0;i<t.size();i++){
            if(s[0]==t[i])p=false;
        }

        for(int i=1;i<s.size();i++){
            for(int j=0;j<t.size();j++){
                if(s[i]==t[j]){
                    if(p)ans++;
                    p=false;
                    break;
                }
                if(j==t.size()-1){
                    if(!p)ans++;
                    p=true;
                }
            }
        }

        cout<<ans<<endl;

    }

}
