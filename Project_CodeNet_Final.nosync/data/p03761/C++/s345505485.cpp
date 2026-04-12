#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>

#define REP(i,a,n) for(int i=a;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define vsort(v) sort(v.begin(),v.end())
#define asort(a,n) sort(a, a + n)
#define vi vector<int>
#define vd vector<double>

//ここからAtCoder向けdefine
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

using namespace std;

int howmany[27][51];

int main(){
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<string> vec(N);
    rep(i, N){
        cin >> vec[i];
    }
    rep(i, N){
        rep(j, vec[i].size()){
            howmany[(int)vec[i].at(j) - 97][i]++;
        }
    }
    int mini[27];
    int m;
    rep(i, 26){
        m = 51;
        rep(j, N){
            if(m > howmany[i][j]){
                m = howmany[i][j];
            }
        }
        mini[i] = m;
    }
    char c;
    rep(i, 26){
        rep(j, mini[i]){
            c = i + 97;
            cout << c;
        }
    }
    cout << endl;

    return 0;
}