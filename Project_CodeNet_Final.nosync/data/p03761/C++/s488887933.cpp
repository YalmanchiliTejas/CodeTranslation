#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include<limits.h>
#include<iomanip>
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(),v.end()
#define RALL(v) v.rbegin(),v.rend()
#define check(v) rep(i,v.size()) cout << v[i] << " ";\
cout << endl
#define INF 1e8
typedef long long ll;
using namespace std;
//オーバーフローに気をつけろよおおおおおお
//確認忘れるなよおおおおおお

int main() {
    int n; cin >> n;
    map<char, int> ans;
    map<char, int> m;

    for(char i = 'a'; i <= 'z'; i++){
        ans[i] = 0;
        m[i] = 0;
    }

    rep(i,n){
        string s; cin >> s;
        if(i==0){
            rep(j,s.size()){
                ans[s[j]]++;
            }
        }else{
            rep(j,s.size()){
                m[s[j]]++;
            }
            for(char j = 'a'; j <= 'z'; j++){
                ans[j] = min(ans[j],m[j]);
            }
            m.clear();
        }
    }
    for(auto ch : ans){
        if(ch.second>=1){
            rep(i,ch.second){
                cout << ch.first;
            }
        }
    }
    cout << endl;
    return 0;
}