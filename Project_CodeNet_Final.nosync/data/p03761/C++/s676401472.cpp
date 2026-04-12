#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    int N;  cin >> N;
    vector<string> S(N);
    for(int i=0; i<N; i++){
        cin >> S[i];
    }

    vector<vector<int>> cnt = vector<vector<int>>(N, vector<int>(26, 0));
    for(int i=0; i<N; i++){
        for(int j=0; j<S[i].length(); j++){
            cnt[i][S[i][j] - 'a']++;
        }
    }
    
    string ans = "";
    for(int i=0; i<26; i++){
        int c = 1e9;
        for(int n=0; n<N; n++){
            c = min(c, cnt[n][i]);
        }
        ans += string(c, 'a' + i);
    }
    cout << ans << endl;
}   