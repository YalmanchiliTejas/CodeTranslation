#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(),v.end()
#define INF 1e9
typedef long long ll;
using namespace std;

int main() {
    int a,b; cin>> a >> b;
    vector<string> v;
    rep(i,a){
        string str; cin >> str;
        int count = 0;
        rep(j,b){
            if(str[j]!='.'){
                count += 1;
            }
        }
        if(count!=0){
            v.push_back(str);
        }
    }

    rep(i,v[0].size()){
        int count = 0;
        rep(j,v.size()){
            if(v[j][i]!='.'){
                count += 1;
            }
        }
        if(count==0){
            rep(k,v.size()){
                v[k][i]=0;
            }
        }
    }
    rep(i,v.size()){
        rep(j,b){
            if(v[i][j]!=0){
                cout << v[i][j];
            }
        }
        cout << endl;
    }


    return 0;
}