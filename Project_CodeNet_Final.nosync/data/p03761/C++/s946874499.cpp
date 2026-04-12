#include <bits/stdc++.h>
using namespace std;

int abc2num(char s){
    if(s == 'a') return 0;
     else if(s == 'b') return 1;
     else if(s == 'c') return 2;
     else if(s == 'd') return 3;
     else if(s == 'e') return 4;
     else if(s == 'f') return 5;
     else if(s == 'g') return 6;
     else if(s == 'h') return 7;
     else if(s == 'i') return 8;
     else if(s == 'j') return 9;
     else if(s == 'k') return 10;
     else if(s == 'l') return 11;
     else if(s == 'm') return 12;
     else if(s == 'n') return 13;
     else if(s == 'o') return 14;
     else if(s == 'p') return 15;
     else if(s == 'q') return 16;
     else if(s == 'r') return 17;
     else if(s == 's') return 18;
     else if(s == 't') return 19;
     else if(s == 'u') return 20;
     else if(s == 'v') return 21;
     else if(s == 'w') return 22;
     else if(s == 'x') return 23;
     else if(s == 'y') return 24;
     else if(s == 'z') return 25;

     return 100;
}

int S[50][26];

int main(){
    int n;
    cin >> n;
    for(int i=0; i < n; i++){
        string s;
        cin >> s;
        for(int j=0; j < (int)s.size(); j++){
            S[i][abc2num(s[j])] += 1;
        }
    }

    int row[26] = {0};
    int nums[26] = {0};
    for(int i=0; i < 26; i++){
        int flag = 0;
        int cnt = 100;
        for(int j=0; j < n; j++){
            if(S[j][i]) flag++;
            cnt = min(cnt, S[j][i]);
        }
        if(flag == n) row[i] = 1;
        nums[i] = cnt;
    }

    //debug
    //for(int i=0; i < 25; i++) cout << row[i] << " " ;
    //for(int i=0; i < 25; i++) cout << nums[i] << " " ;

    //出力用
    string alph[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    string ans = "9";
    for(int i=0; i < 26; i++){
        for(int j=0; j < nums[i]; j++){
            if(row[i]) ans += alph[i];
        }
    }

    cout << ans.substr(1, (int)ans.size()) << endl;

    return 0;
}
