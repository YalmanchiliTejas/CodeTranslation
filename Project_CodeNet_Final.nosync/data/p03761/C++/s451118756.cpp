#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    cin >> N;
    vector<int> cnt(26);
    rep(i,26){
        cnt[i]=100;
    }
    rep(i,N){
        string S;
        cin >> S;
        vector<int> tmp_cnt(26);
        for(int i=0;i<S.length();i++){
            tmp_cnt[S[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            cnt[i]=min(tmp_cnt[i],cnt[i]);
        }
    }
    string ans;
    rep(i,26){
        if(cnt[i]!=0){
            rep(j,cnt[i]){
                ans+=('a'+ i);
            }
        }
    }
    cout << ans << endl;
    return 0;
}