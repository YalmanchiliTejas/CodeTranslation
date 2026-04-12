#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

char another(char c){
    if(c == 'S') return 'W';
    else return 'S';

}

int main(){
    int n;
    string s;
    cin >> n >> s;
    string S[4] = {"SS", "SW", "WS", "WW"};
    for(int j = 0; j < 4; j++){
        bool flag = true;
        for(int i = 1; i < n-1; i++){
            if((S[j][i] == 'S' && s[i] == 'o') || (S[j][i] == 'W' & s[i] == 'x')){
                S[j] += S[j][i-1];
            }
            else{
                S[j] += another(S[j][i-1]);
            }
        }
        if((S[j][n-1] == 'S' && s[n-1] == 'o') || (S[j][n-1] == 'W' & s[n-1] == 'x')){
            if(S[j][0] != S[j][n-2]) flag = false;
        }
        else{
            if(S[j][0] == S[j][n-2]) flag = false;
        }
        if(!flag) continue;
        
        if((S[j][0] == 'S' && s[0] == 'o') || (S[j][0] == 'W' & s[0] == 'x')){
            if(S[j][1] != S[j][n-1]) flag = false;
        }
        else{
            if(S[j][1] == S[j][n-1]) flag = false;
        }
        if(flag){
            cout << S[j] << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}