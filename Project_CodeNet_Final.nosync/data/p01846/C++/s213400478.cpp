#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    while(S != "#"){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a--;b--;c--;d--;
        vector<string> G(15);
        int now = 0;
        for(int i=0; i<S.size(); i++){
            if(S[i] == '/'){
                now++;
            }else{
                if(S[i] == 'b'){
                    G[now].push_back('b');
                }else{
                    int cnt = S[i]-'0';
                    while(cnt){
                        G[now].push_back('.');
                        cnt--;
                    }
                }
            }
        }
        now++;
        swap(G[a][b],G[c][d]);
        string ans = "";
        for(int i=0; i<now; i++){
            int cnt = 0;
            for(int j=0; j<G[i].size(); j++){
                if(G[i][j] == '.'){
                    cnt++;
                }else{
                    if(cnt){
                        ans.push_back(cnt+'0');
                    }
                    cnt = 0;
                    ans.push_back('b');
                }
            }
            if(cnt){
                ans.push_back(cnt+'0');
                cnt = 0;
            }
            if(i != now-1){
                ans.push_back('/');
            }
        }
        cout << ans << "\n";
        cin >> S;
    }
    return 0;
}
