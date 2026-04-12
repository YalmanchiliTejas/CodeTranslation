#include <bits/stdc++.h>
using namespace std;

int main()
{

        int r, g, b;

        cin >> r >> g >> b;

        string S = "123";
        string R = to_string(r);
        string G = to_string(g);
        string B = to_string(b);
        S[0] = R[0];
        S[1] = G[0];
        S[2] = B[0];
        int ans = stoi(S);
        if (ans % 4 == 0) {
                cout << "YES" << endl;
        }
        else {
                cout << "NO" << endl;
        }


}
