#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> s;
    for(int i = 0; i < h; i++){
        string ts;
        cin >> ts;

        bool flg = true;
        for(int j = 0; j < w; j++){
            if(ts[j]=='#'){flg = false;}
        }
        if(!flg){s.push_back(ts);}
    }

    for(int i = 0; i < w; i++){
        bool flg = true;
        for(int j = 0; j < s.size(); j++){
            if(s[j][i]=='#'){
                flg = false;
            }
        }
        if(flg){
            for(int j = 0; j < s.size(); j++){
                s[j][i] = 'a';
            }
        }

    }
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] == 'a'){;}
            else{cout << s[i][j];}
        }
        cout << endl;
    }

    return 0;
}
