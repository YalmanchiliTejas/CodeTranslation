#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<bool> s, t;

void print_result()
{
    for (int i = 0; i < N; i++) {
        cout << (t[i] ? 'S' : 'W');
    }
    cout << endl;
}

bool hidden(int p)
{
    if (p == N-1) {
        if (s[p] != t[p]) {
            if (!t[p-1] == t[0]) {
                print_result();
                return true;
            } else {
                return false;
            }
        } else {
            if (t[p-1] == t[0]) {
                print_result();
                return true;
            } else {
                return false;
            }
        }
    }
    if (s[p] != t[p]) {
        if (p == N-2) {
            if (t[p+1] != !t[p-1]) return false;
        }
        t[p+1] = !t[p-1];
    } else {
        if (p == N-2) {
            if (t[p+1] != t[p-1]) return false;
        }
        t[p+1] = t[p-1];
    }
    return hidden(p+1);
}

bool check(bool f)
{
    t.resize(N);
    t[0] = f;
    if (s[0] != t[0]) {
        t[1] = true;
        t[N-1] = false;       
        if (hidden(1)) return true;
        t[1] = false;
        t[N-1] = true;
        return hidden(1);
    } else {
        t[1] = true;
        t[N-1] = true;
        if (hidden(1)) return true;
        t[1] = false;
        t[N-1] = false;
        return hidden(1);
    }
}

int main()
{
    cin >> N;
    
    string str;
    cin >> str;
    
    s.resize(N);
    for (int i = 0; i < N; i++) {
        s[i] = (str[i] == 'o');
    }
    
    if (!check(true) && !check(false)) cout << -1 << endl;
    
    return 0;   
}