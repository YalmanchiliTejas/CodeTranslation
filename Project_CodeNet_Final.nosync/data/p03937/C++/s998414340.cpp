#include <bits/stdc++.h>


using namespace std;


const int MAXN = 8 + 3;







int h, w, num;
string s[MAXN];


int main() {
    cin >> h >> w;
    for (int i = 0; i < h; i++)
        cin >> s[i];
    int pt = 0, ans = 0, exp = 0;
    for (int i = 0; i < h; i++) {
        bool b = false;
        while (pt < w && s[i][pt] == '#')
            pt++, ans++, b = true;
        if (b)
            pt--;
        exp += count(s[i].begin(), s[i].end(), '#');
    }
    
    if (ans == h + w - 1 && ans == exp)
        cout << "Possible";
    else
        cout << "Impossible";
    return 0;
}