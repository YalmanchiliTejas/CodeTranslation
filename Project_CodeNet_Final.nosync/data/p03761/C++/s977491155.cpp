#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n;cin>>n;
    int a[26];
    memset(a,0,sizeof(a));
    string s;cin>>s;
    int m = s.size();
    rep(i,m)++a[s[i]-'a'];
    
    rep(i,n-1){
        int b[26];
        memset(b,0,sizeof(b));
        string t;cin>>t;
        int m2=t.size();
        rep(j,m2)++b[t[j]-'a'];
        
        rep(k,26)a[k]=min(a[k],b[k]);
    }
    rep(i,26){
      string ans = "a";
      ans[0]+=i;
        rep(j,a[i])cout<<ans;
    }
    cout<<endl;
	return 0;
}