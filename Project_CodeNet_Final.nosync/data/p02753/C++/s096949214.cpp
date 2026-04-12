#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string S;
    cin >> S;

    for (int i = 0; i < 2; i++)
    {
        if (S[i] != S[i + 1])
        {
            cout << "Yes" << endl;
            return 0;
        }
        
    }
    cout << "No" << endl;
  return 0;
}
