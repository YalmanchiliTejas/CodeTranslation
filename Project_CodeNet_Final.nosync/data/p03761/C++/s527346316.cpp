#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int alpha[26];
const int INF = 10000000;

int main(){
    int n; 
    cin >> n;
    vector<string> S(n);
    for(int i = 0; i < n; i++){
        cin >> S[i];
    }
    for(int i = 0; i < 26; i++){
        alpha[i] = INF;
    }
    
    for(char c = 'a'; c <= 'z'; c++){
        if(alpha[c - 'a'] == 0)     continue;
        
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < S[i].length(); j++){
                if(S[i][j] == c){
                    cnt++;
                }
            }
            alpha[c - 'a'] = min(alpha[c - 'a'], cnt);
        }
    }
    
    string ans = "";
    for(char c = 'a'; c <= 'z'; c++){
        int temp = alpha[c - 'a'];
        while(temp > 0){
            ans += c;
            temp--;
        }
    }
    cout << ans << endl;
}