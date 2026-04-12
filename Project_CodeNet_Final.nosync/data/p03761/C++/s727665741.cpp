#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){

    ll N;
    cin >> N;
    vector<string> S(N," ");
    ll S_alpha[N][26];
    memset(S_alpha,0,sizeof(S_alpha));

    for(int i = 0; i < N; i++){
        cin >> S[i];
        for(int j = 0; j < 26; j++){

            for(int k = 0; k < S[i].size(); k++){
                if(S[i][k] - 'a' == j){
                    S_alpha[i][j]++;
                }
            }

        }

    }

    ll ans_alpha[26];
    memset(ans_alpha,0,sizeof(ans_alpha));
    for(int i = 0; i < 26; i++){
        ll tmp = 100;
        for(int j = 0; j < N; j++){
            tmp = min(S_alpha[j][i], tmp);
        }
        ans_alpha[i] += tmp;
    }

    string ans = "";

    for(int i = 0; i < 26; i++){
        for(int j = 0; j < ans_alpha[i]; j++){
            ans += char('a' + i);
        }
    }

    cout << ans << endl;




}   
