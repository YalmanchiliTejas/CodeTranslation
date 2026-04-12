#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(void){
    string s;
    while (cin>>s && s != "#") {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a--, b--, c--, d--;
        
        int h = 1, w = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '/') h++;
            if (h <= 1) {
                if (s[i] == 'b') w++;
                else w += s[i]-'0';
            }
        }
        vector<string> g(h, string(w, '.'));
        
        int th = 0, tw = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '/') th++, tw = 0;
            else if (s[i] == 'b') g[th][tw] = 'b', tw++;
            else tw += s[i]-'0';
        }
        swap (g[a][b], g[c][d]);
        
        string ans;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (g[i][j] == 'b') ans += 'b';
                else {
                    int cnt = 1;
                    while (j+1 < w && g[i][j+1] == '.') cnt++, j++;
                    ans += '0'+cnt;
                }
            }
            if (i < h-1) ans += '/';
        }
        cout << ans << endl;
    }
}