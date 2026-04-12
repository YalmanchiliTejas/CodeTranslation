#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <cstdlib>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    int n, i, j, al[60][30], almax[30];
    string S[60], T;

    cin >> n;

    for(i=0; i<60; i++){
        for(j=0; j<30; j++){
            al[i][j] = 0;
        }
    }

    for(i=0; i<30; i++){
        almax[i] = 100;
    }

    for(i=1; i<=n; i++){
        cin >> S[i];
    }

    for(i=1; i<=n; i++){
        for(j=0; j<S[i].size(); j++){
            al[i][S[i][j]-'a']++;
        }
    }

    for(i=1; i<=n; i++){
        for(j=0; j<26; j++){
            chmin(almax[j], al[i][j]);
        }
    }

    for(i=0; i<26; i++){
        for(j=1; j<=almax[i]; j++){
            T = 'a';
            cout << (char)(T[0]+i);
        }
    }

    cout << endl;

    return 0;
}