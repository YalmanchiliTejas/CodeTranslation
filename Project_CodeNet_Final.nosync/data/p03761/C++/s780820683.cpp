#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)

string S[50];
int moji[50][30];

int main(){
    int n;
    cin >> n;
    REP(i,n){
        cin >> S[i];
    }
    REP(i,n){
        REP(k,S[i].length()){
            moji[i][S[i][k] - 'a']++;
        }
    }

    REP(i, 30){
        int cnt = INT_MAX;
        REP(k,n){
            cnt = min(cnt, moji[k][i]);
        }
        REP(t,cnt){
            printf("%c", 'a'+i);
        }
    }
    printf("\n");
    return 0;
}
