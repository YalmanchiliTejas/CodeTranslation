#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string calc(const string &s, string &&t){
    char last;
    int N = s.size();
    if(t[0]=='S'&&s[0]=='o' || t[0]=='W'&&s[0]=='x'){
        last = t[1];
    } else {
        if(t[1]=='W') last = 'S';
        else last = 'W';
    } 

    for (int i = 2; i < N; i++)
    {
        if(s[i-1]=='o'&&t[i-1]=='S' || s[i-1]=='x'&&t[i-1]=='W' ) t += t[i-2];
        else{
            if(t[i-2]=='W') t+='S';
            else t+='W';
        }
    }

    if(last != t[N-1]) return "";
    
    if(s[N-1]=='o' && t[N-1]=='S' || s[N-1]=='x'&&t[N-1]=='W'){
        if(t[N-2]==t[0]) return t;
        else return "";
    } else {
        if(t[N-2]!=t[0]) return t;
        else return "";
    }
}


int main() {
    int N; cin >> N;
    string s; cin >> s;
    string t;
    if((t = calc(s, "SS")) != ""){
        cout << t << endl;
    } else if ((t = calc(s, "SW")) != ""){
        cout << t << endl;  
    } else if ((t = calc(s, "WS")) != ""){
        cout << t << endl;
    } else if ((t = calc(s, "WW")) != ""){
        cout << t << endl;
    } else {
        cout << -1 << endl;
    }
}