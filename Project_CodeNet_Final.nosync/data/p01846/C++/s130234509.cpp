#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){

    while(1){

	string s; cin >> s;

    if(s == "#") return 0;

    int cnt = 1;
    rep(i,s.size()){
        if(s[i] == '/') cnt ++;
    }

    vector<string> g(cnt, "");

    ll id = 0;

    rep(i,s.size()){

        if(s[i] == 'b'){
            g[id] = g[id] + "b";
            continue;
        }

        else if (s[i] != '/'){

            rep(j,(s[i] - '0')) g[id] = g[id] + ".";
            continue;

        }

        if(s[i] == '/'){
            id++;
            continue;
        }

    }

    //rep(i,cnt){
        //cout << g[i] << endl;
    //}

    int h1, w1, h2, w2; cin >> h1 >> w1 >> h2 >> w2;
    h1--; w1--; h2--; w2--;

    g[h1][w1] = '.'; g[h2][w2] = 'b';

    //rep(i,cnt){
        //cout << g[i] << endl;
    //}

    string ans = "";

    ll tmpi = 0;
    rep(i, cnt){
        rep(j, g[0].size()){

            if(g[i][j] == '.'){
                tmpi++;
                continue;
            }
            
            if(g[i][j] == 'b'){

                if(tmpi == 0){
                    ans = ans + "b";
                }

                else{
                    ans = ans + string(1,(tmpi + '0')) + "b";
                    tmpi = 0;
                }

            }
        }

        if(tmpi != 0) ans = ans + string(1,(tmpi + '0'));
        if(i != cnt -1) ans = ans + "/";

        tmpi = 0;

    }

    cout << ans << endl;

    }

}


