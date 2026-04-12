#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
//const int MODINF = 1000000007;
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<char> s(N);
    vector<char> t_f(N + 1);
    rep(i, 0, N) cin >> s.at(i);
    vector<pair<char, char>> p(4);
    p.at(0) = {'S', 'S'};
    p.at(1) = {'S', 'W'};
    p.at(2) = {'W', 'S'};
    p.at(3) = {'W', 'W'};
    
    for (int k = 0; k < 4; k++){
        vector<char> t(N + 1);
        t.at(0) = p.at(k).first;
        char A;
        rep(i, 0, N){
            if (i == 0){
                A = p.at(k).second;
            }
            else{
                A = t.at(i - 1);
            }
            char z;
            if (t.at(i) == 'W'){
                if (s.at(i) == 'o') z = 'x';
                else z = 'o';
            }
            else{
                if (s.at(i) == 'o') z = 'o';
                else z = 'x';
            }
            if (z == 'o'){
                if (A == 'S') t.at(i + 1) = 'S';
                if (A == 'W') t.at(i + 1) = 'W';
            }
            else{
                if (A == 'S') t.at(i + 1) = 'W';
                if (A == 'W') t.at(i + 1) = 'S';
            }
        }
        if ((p.at(k).second == t.at(N - 1)) && (t.at(0) == t.at(N))){
            rep(i,0,N){
                t_f.at(i) = t.at(i);
            }
            goto SKIP;
        }
        else{
            if (k == 3){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    SKIP:
    rep(i, 0, N){
        cout << t_f.at(i);
    }
    cout << endl;
}