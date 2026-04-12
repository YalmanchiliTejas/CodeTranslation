#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007
 
bool b[100000];
 
int main()
{
    int n;
    string s;
    cin >> n >> s;
 
    for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++){
        bool fl = 0;
        b[0] = i;
        b[1] = j;
        for (int it = 1; it < n - 1; it++){
            if ((b[it] && s[it] == 'o') || (!b[it] && s[it] == 'x')){
                b[it + 1] = b[it - 1];
            }
            else{
                b[it + 1] = !b[it - 1];
            }
        }
 
        if ((b[n - 1] && s[n - 1] == 'o') || (!b[n - 1] && s[n - 1] == 'x')){
            if (b[0] != b[n - 2])
                fl = 1;
        }
        else{
            if (b[0] == b[n - 2])
                fl = 1;
        }
 
        for (int it = 0; it < n; it++){
            if (b[it] && s[it] == 'o'){
                if (b[(it - 1 + n) % n] != b[(it + 1) % n])
                    fl = 1;
            }
            if (b[it] && s[it] == 'x'){
                if (b[(it - 1 + n) % n] == b[(it + 1) % n])
                    fl = 1;
            }
 
            if (!b[it] && s[it] == 'o'){
                if (b[(it - 1 + n) % n] == b[(it + 1) % n])
                    fl = 1;
            }
            if (!b[it] && s[it] == 'x'){
                if (b[(it - 1 + n) % n] != b[(it + 1) % n])
                    fl = 1;
            }
        }
 
        if (!fl){
            for (int it = 0; it < n; it++)
                cout << (b[it] ? 'S' : 'W');
            return 0;
        }
    }
 
    cout << -1 << '\n';
    return 0;
}