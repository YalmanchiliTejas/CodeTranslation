#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    int k;
    long r = 0;
    cin >> n >> k;
    if(k == 1) {
        int c = 0;
        for(int j = 0; j < n.length(); j++) {
            int z = c ? 9 : n[j] - '0';
            if(z)
                r += z;
            if(n[j] != '0')
                c = 1;
        }
    }
    if(k == 2) {
        int b = 0;
        for(int i = 0; i < n.length(); i++) {
            int y = b ? 9 : n[i] - '0', c = 0;
            for(int j = i + 1; j < n.length(); j++) {
                int z = b + c ? 9 : n[j] - '0';
                if(y)
                    r += (y - 1) * 9;
                if(y && z)
                    r += z;
                if(n[j] != '0')
                    c = 1;
            }
            if(n[i] != '0')
                b = 1;
        }
    }
    if(k == 3) {
        int a = 0;
        for(int l = 0; l < n.length(); l++) {
            int x = a ? 9 : n[l] - '0', b = 0;
            for(int i = l + 1; i < n.length(); i++) {
                int y = a + b ? 9 : n[i] - '0', c = 0;
                for(int j = i + 1; j < n.length(); j++) {
                    int z = a + b + c ? 9 : n[j] - '0';
                    if(x)
                        r += (x - 1) * 81;
                    if(x && y)
                        r += (y - 1) * 9;
                    if(x && y && z)
                        r += z;
                    if(n[j] != '0')
                        c = 1;
                }
                if(n[i] != '0')
                    b = 1;
            }
            if(n[l] != '0')
                a = 1;
        }
    }
    cout << r << endl;
    return 0;
}
