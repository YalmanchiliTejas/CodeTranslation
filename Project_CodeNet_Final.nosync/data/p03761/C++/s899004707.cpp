#include<string>
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    string s[n];
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    int map[n][26];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            map[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++){
        int len = s[i].length();
        for(int j = 0; j < len; j++){
            map[i][s[i][j] - 'a']++;
        }
    }

    string ans;
    int cou = 51;

    for(int i = 0; i < 26; i++){
        cou = 51;
        for(int j = 0; j < n; j++){
            if(map[j][i] == 0){
                cou = 0;
                break;
            }else{
                if(cou >= map[j][i]){
                    cou = map[j][i];
                }
            }
        }

        for(int j = 0; j < cou; j++){
            ans += 'a' + i;
        }
    }

    cout << ans << endl;
}