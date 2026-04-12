#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
        int X;
        cin >> X;
        bool ok(false);
        if (X == 3 || X == 5 || X == 7) {
                ok = true;
        }

        cout << ((ok) ? "YES" : "NO") << endl;
        return 0;
}
