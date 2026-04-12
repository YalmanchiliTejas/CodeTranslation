#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <string>
#include <set>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> mp(h);
    string str;
    vector<int> vh,vw;
    set<int> sh,sw;

    rep(i,h){
        bool flag = false;
        cin >> str;
        rep(j,str.length()){
            if(str[j] == '#'){
                flag = true;
                break;
            }
        }
        if(!flag)sh.insert(i);

        mp[i] = str;
    }

    rep(i,w){
        bool flag = false;
        rep(j,h){
            if(mp[j][i] == '#'){
                flag = true;
                break;
            } 
        }
        if(!flag) sw.insert(i);
    }

    rep(i,h){
        //if(sh.count(i) > 0 ) break;
        rep(j,w){
            if(sw.count(j) == 0 && sh.count(i) == 0 ){
                cout << mp[i][j];
            }
        }
        if(sh.count(i) == 0){
            cout << endl;
        }
    }
    return 0;
}