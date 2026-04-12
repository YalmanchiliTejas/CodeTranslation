#include "bits/stdc++.h"
using namespace std;
#define FOR(i,a,b) for(int i =(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPm(i,n) for(int i=(n)-1;i>=0;i--)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define mp make_pair
typedef long long ll;
int main(){
    char in;
    char vowel[5] = {'a','e','i','o','u'};
    cin >> in;
    bool ans = false;
    REP(i,5) if(in == vowel[i]) ans = true;
    if(ans) cout << "vowel" << endl;
    else cout << "consonant" << endl;
    return 0;
}
