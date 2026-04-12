#include<bits/stdc++.h>
using namespace std;

int solve(string s){
    string left = "qwertasdfgzxcvb";
    map<char,bool> m;
    for(int i = 0;i < left.size();i++){
        m[left[i]] = true;
    }
    int res = 0;
    bool hand = m[s[0]];
    for(int i = 1;i < s.size();i++){
        if(hand != m[s[i]]){
            hand = !hand;
            res++;
        }
    }
    return res;
}

int main(){
    string s;
    while(true){
        cin >> s;
        if(s == "#")return 0;
        cout << solve(s) << endl;
    }
}
