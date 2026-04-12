#include <iostream>

using namespace std;

string f(int x) {
    if (x == 7 || x == 5 || x == 3) {
        return "YES";
    }
    return "NO";
}

int main() {

    int x;
    cin >> x;

    string result = f(x);
    cout << result << endl;

    return 0;
}
