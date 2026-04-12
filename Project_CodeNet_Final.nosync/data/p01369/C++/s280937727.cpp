#include<bits/stdc++.h>
using namespace std;

string keys[2] = {
    "qwertasdfgzxcvb",
    "yuiophjklnm"
};

int main(){
    string s;
    while(cin >> s, s[0] != '#'){
        int id = (keys[0].find(s[0]) != -1? 0 : 1), cnt = 0;
        for(char c : s){
            if(keys[id].find(c) == -1){
                cnt++;
                id ^= 1;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
