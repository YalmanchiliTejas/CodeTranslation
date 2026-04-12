#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<string> str(n);
    rep(i,n) cin >> str[i];
    int table[51][26] = {0};
    string alp = "abcdefghijklmnopqrstuvwxyz";

    rep(i,n){
        rep(j,str[i].length()){
            int num = (int)(str[i][j] - 'a');
            table[i][num]++;
        }
    }

    vector<int> mindata(26,1000);
    rep(i,26){
        rep(j,n){
            mindata[i] = min(mindata[i],table[j][i]);
        }
    }
    rep(i,26){
        rep(j,mindata[i]){
            cout << alp[i];
        }
    }

cout << endl;
    return 0;
}