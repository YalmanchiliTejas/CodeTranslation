#include <iostream>
#include <string>
#include <vector>
using namespace std;

int l[] = {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,0,1};

int main() {
    string s;
    while (cin >> s) {
        if (s == "#") break;
        int cnt = 0;
        for (int i=1; i<(int)s.size(); ++i) {
            cnt += l[s[i-1] - 'a'] ^ l[s[i] - 'a'];
        }
        cout << cnt << endl;
    }
    return 0;
}