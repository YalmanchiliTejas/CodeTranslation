#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define int long long
using namespace std;

typedef pair<int, int> Pii;

void readint(int N, vector<int> &a);
void readdouble(int N, vector<double> &a);
void readindex(int N, vector<int> &a);



signed main(){

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int MAX_N = 100000;

    int ans = MAX_N * 50000;

    int a, b, v;
    REP(c2, MAX_N + 1){
        a = max((int)0, X - c2);
        b = max((int)0, Y - c2);
        v = a * A + b * B + 2 * c2 * C;
        if(v < ans) ans = v; 
    }

    cout << ans;
    
    return 0;
}








void readint(int N, vector<int> &a){
    string s;
    for(int i = 0; i < N - 1; i++){
        getline(cin, s, ' ');
        a[i] = atoi(s.c_str());
    }
    getline(cin, s, '\n');
    a[N - 1] = atoi(s.c_str());
}
void readdouble(int N, vector<double> &a){
    string s;
    for(int i = 0; i < N - 1; i++){
        getline(cin, s, ' ');
        a[i] = atof(s.c_str());
    }
    getline(cin, s, '\n');
    a[N - 1] = atof(s.c_str());
}
void readindex(int N, vector<int> &a){
    string s;
    for(int i = 0; i < N - 1; i++){
        getline(cin, s, ' ');
        a[i] = atoi(s.c_str()) - 1;
    }
    getline(cin, s, '\n');
    a[N - 1] = atoi(s.c_str()) - 1;
}