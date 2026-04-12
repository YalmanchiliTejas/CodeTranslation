#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
int64_t INF = 1000000007;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    int64_t h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s.at(i);
    bool complete = false;
    while(!complete){
        // 行を削除
        vector<string> s2;
        rep(i,s.size()){
            rep(j,s.at(0).size()){
                if(s.at(i).at(j) == '#'){
                    s2.push_back(s.at(i));
                    break;
                }
            }
        }
        // 列を削除
        vector<string> s3(s2.size());
        rep(j,s2.at(0).size()){
            rep(i,s2.size()){
                if(s2.at(i).at(j) == '#'){
                    rep(k,s2.size()){
                        s3.at(k).push_back(s2.at(k).at(j));
                    }
                    break;
                }
            }
        }
        complete = s.size()==s3.size() && s.at(0).size() == s3.at(0).size();
        s = s3;
    }
    rep(i,s.size()){
        rep(j,s.at(0).size()){
            cout << s.at(i).at(j);
        }
        cout << endl;
    }
}