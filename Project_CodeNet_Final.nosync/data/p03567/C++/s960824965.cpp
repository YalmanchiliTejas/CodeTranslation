#include "bits/stdc++.h"
using namespace std;
#define FOR(i,a,b) for(int i =(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPm(i,n) for(int i=(n)-1;i>=0;i--)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define mp make_pair
typedef long long ll;
int main(){
    string s;
    cin >> s;
    bool ans = false;
    REP(i,s.length()-1){
        if(s.substr(i,2) == "AC") ans = true;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
