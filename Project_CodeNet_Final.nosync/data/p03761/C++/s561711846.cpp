#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int ans[30];
int cnt[55][30];

int main(){
    int n; cin>>n;
    fill(ans,ans+30,INF);
    for(int i=0;i<n;i++){
        string s; cin>>s;
        for(int j=0;j<s.size();j++){
            cnt[i][s[j]-'a']++;
        }
        for(int j=0;j<30;j++){
            ans[j]=min(ans[j],cnt[i][j]);
        }
    }
    for(int i=0;i<30;i++){
        while(ans[i]>0){
            cout<<(char)('a'+i);
            ans[i]--;
        }
    }
    cout<<endl;
}
