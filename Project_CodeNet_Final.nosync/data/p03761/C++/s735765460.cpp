#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
    
int main(){
    int n;
    cin >> n;
    vector <string> t(n);
    rep(i,n){
        string s;
        cin >> s;
        sort(all(s));
        t[i] = s;
    }

    map <char,int> table;
    for(char i='a'; i <='z'; i++){
        int cnti = count(all(t[0]),i);
        for(int j=0; j < n; j++){
            int cnt = count(all(t[j]),i);
            if(cnt < cnti){
                cnti = cnt;
            }
        }
        table[i] = cnti;
    }

    string ans = "";

    for(char i = 'a' ;  i <= 'z'; i++){
        if(table.at(i) >= 1){
            for(int j=0; j<table.at(i); j++){
                ans.push_back(i);
            }
        }
    }

    cout << ans << endl;
}