#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    string s; cin >> s;
    string ans1 = "SS", ans2 = "SW", ans3 = "WS", ans4 = "WW";
    char c1 = (s[0]=='o') ? 'S' : 'W', c2 = (s[0]=='o') ? 'W' : 'S';
    char c3 = (s[0]=='o') ? 'W' : 'S', c4 = (s[0]=='o') ? 'S' : 'W';
    vector<string> v;
    v.push_back(ans1);v.push_back(ans2);v.push_back(ans3);v.push_back(ans4);
    vector<char> w;
    w.push_back(c1);w.push_back(c2);w.push_back(c3);w.push_back(c4);
    int x = -1;
    for (string k : v){
        x++;
        for (int i = 2; i < n; i++)
        {
            if (k[i-1] == 'S'){
                if (k[i-2] == 'S'){
                    if (s[i-1] == 'o'){
                        k.push_back('S');
                    }
                    else{
                        k.push_back('W');
                    }
                }
                else{
                    if (s[i-1] == 'o'){
                        k.push_back('W');
                    }
                    else{
                        k.push_back('S');
                    }
                }
            }
            else{
                if (k[i-2] == 'S'){
                    if (s[i-1] == 'o'){
                        k.push_back('W');
                    }
                    else{
                        k.push_back('S');
                    }
                }
                else{
                    if (s[i-1] == 'o'){
                        k.push_back('S');
                    }
                    else{
                        k.push_back('W');
                    }
                }
            }
        }
        if (s[n-1] == 'o'){
            if (k[n-1] == 'S'){
                if (k[n-2] != k[0])continue;
            }
            else {
                if (k[n-2] == k[0])continue;
            }
        }
        else {
            if (k[n-1] == 'S'){
                if (k[n-2] == k[0])continue;
            }
            else {
                if (k[n-2] != k[0])continue;
            }
        }
        if (k[n-1] == w[x]){
            cout << k << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
    