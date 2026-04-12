#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> alp(26,0);
    rep(i,n){
        string s;
        cin >> s;
        vector<int> now(26);
        rep(j,s.size()) now[s[j] - 'a']++;
        if(i == 0){
            rep(j,26)alp[j] = now[j];
        }
        else{
            rep(j,26) alp[j] = min(alp[j],now[j]);
        }
    }
    rep(i,26){
        cout << string(alp[i],i+'a');
    }
    cout << endl;
}