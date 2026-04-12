#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MOD 1000000007
#define PI 3.141592653589793

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> v(h);
    for(int i = 0; i < h; i++)
        cin >> v[i];

    for(int i = 0; i < h; i++){
        string s = v[i];
        bool ok = all_of(s.begin(), s.end(), [](char x){return x == '.';});
        if(ok){
            for(auto &c: v[i])
                c = 's';
        }
    }

    for(int i = 0; i < w; i++){
        if(v[0][i] == '.' || v[0][i] == 's'){
            bool ok = true;
            for(auto s: v)
                if(s[i] == '#')
                    ok = false;

            if(ok)
                for(auto &s: v)
                    s[i] = 's';
        }
    }
    for(auto s: v){
        int cnt = 0;
        for(auto c: s){
            if(c != 's')
                cout << c;
            else
                cnt++;
        }
        if(cnt == w)
            continue;
        cout << '\n';
    }
}
