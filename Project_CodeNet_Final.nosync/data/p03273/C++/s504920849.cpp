#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl

int main() {
    int h, w; cin >> h >> w;
    vector<string> a(h+2);
    rep(i, h) rep(j, w) {
        char x; cin >> x;
        a.at(i) += x;
    }

//    dump(a.at(0));

    vector<string> b;
    string t = "";
    rep(i, w) t += '.';
    rep(i, h){
        if(t==a.at(i)) continue;
        else b.push_back(a.at(i));
    }

    rep(i, b.size()) dump(b.at(i));

    vector<string> c(b.size(), "");
    bool skip = false;
    rep(i, w){
        rep(j, b.size()){
            if(b.at(j).at(i)=='#'){
                break;
            }

            if(j==b.size()-1){
               skip = true; 
            }
        }

        if(skip) {
            skip = false;
            continue;
        }
        else{
            rep(j, b.size()){
                c.at(j) += b.at(j).at(i);
            }
        }
    }

    rep(i, c.size()) cout << c.at(i) << endl;

}