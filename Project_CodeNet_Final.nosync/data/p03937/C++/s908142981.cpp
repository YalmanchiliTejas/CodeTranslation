// AGC 007 A
#include <bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define ll long long
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    char A[H][W];
    REP(i,H){
        REP(k,W){
            cin >> A[i][k];}}
    int c = 0;
    REP(i,H){
        REP(k,W){
            if (A[i][k]=='#') c++;}}
    cout << (c==H+W-1?"Possible":"Impossible") << endl;
    return 0;
}
