#include <bits/stdc++.h>
using namespace std;

static const int INF = 55;

int main(){
    int N;
    cin>>N;
    vector<string> S(N);
    for(int i=0; i<N; i++) cin>>S[i];

    vector<int> cnt(26,INF);

    for(int i=0; i<N; i++){
        vector<int> cp(26,0);
        for(int j=0; j<S[i].size(); j++){
            cp[(int)(S[i][j] - 'a')]++;
        }
        for(int j=0; j<26; j++){
            cnt[j] = min(cp[j],cnt[j]);
        }
    }

    string ans = "";
    int start = 0;

    for(int i=0; i<26; i++){
        if(cnt[i] == INF) cnt[i] == 0;
    }

    while(start < 26){
        if(cnt[start] == 0){
            start++;
            continue;
        }

        ans += char('a' + start);
        cnt[start]--;
    }

    cout<<ans<<endl;

    return 0;
}