#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MOD = 1e9+7;


int main(){
    int N; cin >> N;
    vector<map<char, int>> M(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 26; j++){
            //cout << (char)(j+97) << endl;
            M[i][(char)(j+97)] = 0;
        }
    }
    for(int i = 0; i < N; i++){
        string S; cin >> S;
        for(auto c : S)M[i][c]++;
    }

    vector<int> Min(26);
    for(int i = 0; i < 26; i++) Min[i] = INF;
    for(int i = 0; i < N; i++){
        for(auto m : M[i]){
            char ch = m.first;
            int num = m.second;
            Min[(int)ch-97] = min(num, Min[(int)ch-97]);
        }
    }

    string ans = "";
    for(int i = 0; i < 26; i++){
        if(Min[i] == INF) continue;
        for(int j = 0; j < Min[i]; j++){
            ans += (char)(i + 97);
        }
    }
    cout << ans << endl;

}
