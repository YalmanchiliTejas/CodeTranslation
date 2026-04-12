#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin>>n;
    string s[60];
    rep(i,n)cin>>s[i];
    string ans;
    for(char c='a';c<='z';c++){
        int small=300;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<s[i].size();j++){
                if(s[i][j]==c)cnt++;
            }
            small=min(small,cnt);
        }
        for(int i=0;i<small;i++)ans+=c;
    }
    cout<<ans<<endl;
}