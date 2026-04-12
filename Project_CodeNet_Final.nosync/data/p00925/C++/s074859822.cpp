#include<bits/stdc++.h>
using namespace std;

long long dfs(int& idx, string s){
    if(s[idx + 1] == '+') return (int)s[idx] - '0';
    else{
        idx += 2;
        return ((int)s[idx - 2] - '0') * dfs(idx, s);
    }
}

int main(){

    string s; cin >> s;
    s = s + '+';
    long long n; cin >> n;
    long long rule1;
    long long rule2 = 0;
    //rule2
    int idx = 0;
    while(idx < s.size()){
        rule2 += dfs(idx, s);
        idx += 2;
    }

    //rule1
    for(int i = 0; i < s.size(); i += 2){
        if(i == 0) rule1 = (int)s[i] - '0';
        else{
            if(s[i - 1] == '+') rule1 += (int)s[i] - '0';
            else rule1 *= (int)s[i] - '0';
        }
    }

    if(rule1 == n && rule2 == n) cout << 'U' << endl;
    else if(rule1 == n) cout << 'L' << endl;
    else if(rule2 == n) cout << 'M' << endl;
    else cout << 'I' << endl;
    return 0;
}
