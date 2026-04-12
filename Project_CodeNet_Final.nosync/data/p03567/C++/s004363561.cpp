#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i) = 0; (i) < (n); ++(i))
#define rrep(i,n) for(int (i) = (n) - 1; (i) >= 0; --(i)) //Reversi rep
#define nfor(i,a,b) for(int (i) = (a); (i) < (b); ++(i)) //Natural for
#define rfor(i,a,b) for(int (i) = (b); (i) >= (a); --(i)) //Reversi for
#define mod (1000000007)
#define YES cout << "YES" << endl;
#define Yes cout << "Yes" << endl;
#define NO cout << "NO" << endl;
#define No cout << "No" << endl;

int asc(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int desc(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int main()
{
    string s;
    cin >> s;
    bool ans = false;
    rep(i, s.size()-1)if(s[i] == 'A' && s[i + 1] == 'C')ans = true;
    if (ans) {
        Yes;
    }else{
        No;
    }
    return 0;
}