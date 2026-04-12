#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s;
    while(cin >> s, s != "#") {
        vector<string> v(1);
        for(int i=0; i<s.size(); ++i) {
            if(s[i] == '/') {
                v.push_back("");
            } else if('1' <= s[i] && s[i] <= '9') {
                for(int j=0; j<(s[i] - '0'); ++j) {
                    v[v.size()-1] += '.';
                }
            } else {
                v[v.size()-1] += 'b';
            }
        }
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v[a-1][b-1] = '.';
        v[c-1][d-1] = 'b';

        string res;
        for(int i=0; i<v.size(); ++i) {
            int cnt = 0;
            for(int j=0; j<v[i].size(); ++j) {
                if(v[i][j] == 'b') {
                    if(cnt > 0) {
                        res += '0' + cnt;
                    }
                    res += 'b';
                    cnt = 0;
                } else {
                    cnt++;
                }
            }
            if(cnt > 0) {
                res += '0' + cnt;
            }
            if(i != v.size()-1) {
                res += '/';
            }
        }
        cout << res << endl;
    }
}
