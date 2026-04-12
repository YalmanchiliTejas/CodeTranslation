#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n; cin >> n;
    string S[n];
    for(int i=0; i<n; i++) cin >> S[i];

    string ans="";
    for(char c='a'; c<='z'; c++){
        int cnt=50;
        
        for(int i=0; i<n; i++){

            int tmp=0;
            for(int j=0; j<S[i].size(); j++){
                if(S[i][j]==c) tmp++;
            }
            cnt=min(cnt,tmp);
        }
        
        for(int i=0; i<cnt; i++) ans+=c;
    }

    cout << ans << endl;
    return 0;
}