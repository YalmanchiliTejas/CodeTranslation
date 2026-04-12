#include <bits/stdc++.h>
using namespace std;

string make(string t, string s){
    for(int i = 1; i < s.size(); i++){
        if(s[i] == 'o'){
            if(t[i] == 'S') t += t[i-1];
            else t += t[i-1] == 'S' ? 'W' : 'S';
        }else{
            if(t[i] == 'W') t += t[i-1];
            else t += t[i-1] == 'S' ? 'W' : 'S';
        }
    }
    return t;
}

int main(){
    int n;
    string s;
    cin >> n >> s;
    string tmp[4] = {"SS", "SW", "WS", "WW"};
    for(int i = 0; i < 4; i++)
    for(int i = 0; i < 4; i++){
        string res = make(tmp[i], s);
        if(res[0] == res[n]){
            if(s[0] == 'o'){
                if(res[0] == 'S'){
                    if(res[1] == res[n-1]){
                        cout << res.substr(0, n) << endl;
                        return 0;
                    }
                }else{
                    if(res[1] != res[n-1]){
                        cout << res.substr(0, n) << endl;
                        return 0;
                    }
                }
            }else{
                if(res[0] == 'W'){
                    if(res[1] == res[n-1]){
                        cout << res.substr(0, n) << endl;
                        return 0;
                    }
                }else{
                    if(res[1] != res[n-1]){
                        cout << res.substr(0, n) << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}