#include <math.h>
#include <ctype.h>
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(i, n) for(int i = 0; i < n; i++)
struct omt{omt(){ios::sync_with_stdio(false);cin.tie(0);}}star;

int main(){
    string r, g, b;
    cin >> r >> g >> b;
    
    r += g + b;
    int a = stoi(r);
    if(a % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}