#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> s(n);
    string ans;
    for(int i=0;i<n;i++) cin >> s[i];
    char now = 'a';
    for(char c=now;c<='z';c++){
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<s[i].size();j++){
                if(s[i][j]==c){
                    s[i].erase(s[i].begin()+j);
                    cnt++;
                    break;
                }
            }
        }
        if(cnt==n){
            ans += c;
            now = c--;
        }
    }
    cout << ans << endl;
    return 0;
}