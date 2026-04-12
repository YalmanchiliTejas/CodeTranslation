#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int cnt[n][26];
    memset(cnt,0,sizeof(cnt));
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<s.size();j++){
            cnt[i][s[j]-'a']++;
        }
    }
    string ans = "";
    for(int i=0;i<26;i++){
        int minn = INT_MAX;
        for(int j=0;j<n;j++){
            minn = min(minn,cnt[j][i]);
        }
        string s(minn,(char)(i+'a'));
        ans += s;
    }
    sort(ans.begin(),ans.end());
    cout<<ans<<"\n";
    return 0;
}


