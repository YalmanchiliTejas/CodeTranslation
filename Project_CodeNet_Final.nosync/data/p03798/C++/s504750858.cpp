#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

int n;
string s;
char a[2]={'S','W'};

string ok(int f,int t){
    string ans = "";
    ans += a[f];
    ans += a[t];
    char key;
    if((s[0]=='o'&&a[f]=='S')||(s[0]=='x'&&a[f]=='W')){
        key = a[t];
    }
    else{
        key = a[!t];//少し心配
    }
    for(int i=1;i<n;i++){
        if((s[i]=='o'&&ans[i]=='S')||(s[i]=='x'&&ans[i]=='W')){
            ans += ans[i-1];
        }
        else{
            rep(j,2){
                //１つ前と違うものをたす
                if(a[j]==ans[i-1])continue;
                ans += a[j];
            }
        }
    }
    if(ans[n]!=ans[0])return "NO";
    if(ans[n-1]==key){
        ans.pop_back();
        return ans;
    }
    else{
        return "NO";
    }
}
int main(){
    cin >> n;
    cin >> s;
    rep(i,2)rep(j,2){
        if(ok(i,j)!="NO"){
            cout << ok(i,j) << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
