#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(int n, string &s, vector<int> &t) {
    for (int i = 0; i < n; i++) {
        if (t[i] && s[i] == 'o' && t[(i+1)%n] == t[(i-1+n)%n])
            return false;
        else if (t[i] && s[i] == 'x' && t[(i+1)%n] != t[(i-1+n)%n])
            return false;
        else if (!t[i] && s[i] == 'x' && t[(i+1)%n] == t[(i-1+n)%n])
            return false;
        else if (!t[i] && s[i] == 'o' && t[(i+1)%n] != t[(i-1+n)%n])
            return false;
    }
    return true;
}

bool construct(int n, string &s, int u, int v, vector<int> &t) {
    t.resize(n);
    t[0] = u;   t[1] = v;
    for (int i = 2; i < n; i++) {
        if (s[i-1] == 'o' && t[i-1])
            t[i] = 1-t[i-2];
        else if (s[i-1] == 'o' && !t[i-1])
            t[i] = t[i-2];
        else if (s[i-1] == 'x' && t[i-1])
            t[i] = t[i-2];
        else 
            t[i] = 1 - t[i-2];
    }
    
    return check(n, s, t);
}

int main() {
    int n;  cin >> n;
    string s;   cin >> s;
    vector<int> t;
    char c[] = {'S', 'W'};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (construct(n, s, i, j, t)) {
                for (int k = 0; k < n; k++)
                    cout << c[t[k]];
                cout << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}