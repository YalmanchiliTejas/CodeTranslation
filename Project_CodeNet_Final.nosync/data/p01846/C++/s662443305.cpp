#include <iostream>
#include <string>
#define MAX_H 10
using namespace std;

string jfen[MAX_H];
int jfen_height;

void printJfen() {
    string ans;
    for (int i = 0; i < jfen_height; i++) {
        int count = 0;
        for (int j = 0; j < jfen[i].length(); j++) {
            if (jfen[i][j] == 'b') {
                if (count > 0) {
                    ans.push_back(count + '0');
                }
                ans.push_back('b');
                count = 0;
            } else {
                count++;
                if (j == jfen[i].length() - 1) {
                    ans.push_back(count + '0');
                }
            }
        }
        if (i < jfen_height - 1) ans.push_back('/');
    }

    cout << ans << endl;
}

void makeJfen(string s) {
    int height = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'b') {
            jfen[height].push_back('b');
        } else if (s[i] == '/') {
            height++;
        } else {
            int temp = s[i] - '0';
            for (int j = 0; j < temp; j++) {
                jfen[height].push_back('.');
            }
        }
    }    
    jfen_height = height + 1;
}

int main() {
    while (true) {
        string s;
        cin >> s;
        if (s == "#") return 0;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = 0; i < MAX_H; i++) {
            jfen[i].erase();
        }

        makeJfen(s);
        
        char temp = jfen[a - 1][b - 1];
        jfen[a - 1][b - 1] = jfen[c - 1][d - 1];
        jfen[c - 1][d - 1] = temp;

        printJfen();
        //for (int i = 0; i < jfen_height; i++) {
        //    cout << jfen[i] << endl;
        //}
    }
    
}