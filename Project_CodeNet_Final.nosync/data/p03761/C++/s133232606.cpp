#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    string ans;
    rep(i,n) cin >> s[i];
    for(int i = 'a'; i<= 'z'; i++){
        int min_cnt = 10000000;
        rep(j,n){
            int cnt=0;
            rep(k,s[j].size()){
                if(s[j][k] == i) cnt++;
            }
            min_cnt = min(min_cnt,cnt);
        }
        rep(k,min_cnt){
            ans.push_back(i);
        }
    }
    cout << ans << endl;
}