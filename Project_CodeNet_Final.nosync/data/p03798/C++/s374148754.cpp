#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    string str[4]={"SS","SW","WS","WW"};

    string two;
    for(int i = 1; i < n+1; i++){
        for(int j = 0; j < 4; j++){
            two = str[j].substr(i-1,2);
            if(two == "SS"){
                str[j] += s[i%n]=='o' ? "S" : "W";
            }else if(two == "SW"){
                str[j] += s[i%n]=='o' ? "W" : "S";
            }else if(two == "WS"){
                str[j] += s[i%n]=='o' ? "W" : "S";
            }else if(two == "WW"){
                str[j] += s[i%n]=='o' ? "S" : "W";
            }
        }
    }
    for(int i = 0; i < 4; i++){
        if(str[i][0] == str[i][n] && str[i][1] == str[i][n+1]){
            cout << str[i].substr(0,n) << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}
