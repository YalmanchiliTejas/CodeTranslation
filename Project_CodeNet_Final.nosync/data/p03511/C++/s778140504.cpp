#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main() {
        int l;
        scanf("%d", &l);
        string s, t;
        cin >> s >> t;
        if (s + t > t + s) swap(s, t);
        int p = 1 << 30, q = 1 << 30;
        for (int left = l; left >= 0; left --) {
                int right = l - left;
                if (left % (int)s.size() == 0 && right % (int)t.size() == 0) {
                        p = left, q = right;
                        break;
                }
        }
        int lcnt = p / (int)s.size(); 
        int rcnt = q / (int)t.size();
        while (lcnt --) cout << s;
        while (rcnt --) cout << t;
        cout << endl;
        return 0;
}

