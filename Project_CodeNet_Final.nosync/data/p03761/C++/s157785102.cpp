#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<string>s(n);
    rep(i,n)cin>>s.at(i);
    vector<int>vec(26,100);
    rep(i,n){
        vector<int>tmp(26);
        rep(j,s.at(i).size()) tmp.at(s.at(i).at(j)-'a')++;
        rep(i,26) vec.at(i)=min(vec.at(i),tmp.at(i));
    }
    
    string ans;
    rep(i,26){
        rep(j,vec.at(i)) ans+='a'+i;
    }
    cout<<ans<<endl;
}
