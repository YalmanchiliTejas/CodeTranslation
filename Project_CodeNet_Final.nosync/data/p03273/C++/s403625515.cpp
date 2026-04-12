//#include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<numeric>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<map>
#include<stack>
#include<queue>
#include<ctype.h>
#include <fstream>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;//int64
typedef unsigned long long ull;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a*b/gcd(a,b);}
int dy[4]={0,1,0,-1};
//----------program from here----------

int main(){
    int H=0, W=0;
    cin >> H >> W;
    char a[H][W];
    bool d_H[H], d_W[W];
    for(int i=0; i<H; ++i)
        for(int j=0; j<W; ++j)
            cin >> a[i][j];
    for(int i=0; i<H; ++i)
        d_H[i] = false;
    for(int i=0; i<W; ++i)
        d_W[i] = false;
    
    for(int i=0; i<H; ++i){
        bool flag = true;
        for(int j=0; j<W; ++j){
            if(a[i][j]=='#'){
                flag = false;
                break;
            }
        }
        if(flag) d_H[i] = true;
    }

    for(int j=0; j<W; ++j){
        bool flag = true;
        for(int i=0; i<H; ++i){
            if(a[i][j]=='#'){
                flag = false;
                break;
            }
        }
        if(flag) d_W[j] = true;
    }

    for(int i=0; i<H; ++i){
        for(int j=0; j<W; ++j){
            if(!d_H[i]&&!d_W[j])
                cout << a[i][j];
        }
        if(!d_H[i])
            cout << endl;
    }
}