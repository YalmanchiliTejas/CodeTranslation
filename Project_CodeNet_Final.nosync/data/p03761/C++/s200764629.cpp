#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << x << " = "(x) << endl;
#define ll long long
#define rep(i,x,y) for(int i=x;i<y;i++)
#define rel(i,x,y) for(int i=x-1;i>=y;i--)
#define all(x) x.begin(),x.end()

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int n; cin >> n;
    vector<string> s(n);
    rep(i,0,n) cin >> s[i];
    int alpha[26] = {};
    rep(i,0,s[0].size()){
        alpha[s[0][i]-'a']++;
    }
    rep(i,0,n){
        int tmp[26] = {};
        rep(j,0,s[i].size()){
            tmp[s[i][j]-'a']++;
        }
        rep(j,0,26){
            alpha[j] = min(alpha[j],tmp[j]);
        }
    }
    rep(i,0,26){
        rep(j,0,alpha[i]){
            cout << (char)('a'+i);
        }
    }
    cout << endl;
}