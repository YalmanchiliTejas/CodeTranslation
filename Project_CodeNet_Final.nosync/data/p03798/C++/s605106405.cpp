#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    string s; cin >> s;
    char t[N];
    for (int k = 0; k < 4; k++){
        if(k>>0&1){
            t[0] = 'S';
        } else {
            t[0] = 'W';
        }
        if(k>>1&1){
            t[1] = 'S';
        } else {
            t[1] = 'W';
        }

        for (int i = 1; i < N-1; i++){
            if(s[i] == 'o' && t[i] == 'S'){
                t[i+1] = t[i-1];
            } else if(s[i] == 'x' && t[i] == 'W'){
                t[i+1] = t[i-1];
            } else {
                if(t[i-1] == 'S'){
                    t[i+1] = 'W';
                } else {
                    t[i+1] = 'S';
                }
            }
        }

        bool ok = true;
        if(s[N-1] == 'o' && t[N-1] == 'S'){
            if(t[N-2] != t[0]){
                ok = false;
            }
        } else if(s[N-1] == 'x' && t[N-1] == 'W'){
            if(t[N-2] != t[0]){
                ok = false;
            }
        } else {
            if(t[N-2] == t[0]){
                ok = false;
            }
        }

        if(s[0] == 'o' && t[0] == 'S'){
            if(t[N-1] != t[1]){
                ok = false;
            }
        } else if(s[0] == 'x' && t[0] == 'W'){
            if(t[N-1] != t[1]){
                ok = false;
            }
        } else {
            if(t[N-1] == t[1]){
                ok = false;
            }
        }

        if(ok){
            rep(i, N){
                cout << t[i];
            }
            cout << endl;
            return 0;
        } else {
            continue;
        }
    }
    cout << -1 << endl;

    return 0;
}