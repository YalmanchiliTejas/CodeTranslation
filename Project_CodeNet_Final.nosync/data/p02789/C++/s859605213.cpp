#include <iostream>
#include <string>
using namespace std;

void _150() {
    string s;
    cin >> s;

    if ((s == "AAA") || (s == "BBB"))
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}

void _156() {
    int n, r;
    cin >> n >> r;

    if (n >= 10)
        cout << r << endl;
    else
        cout << r + 100 * (10 - n) << endl;
}

void _155() {
    int a, b, c;
    cin >> a >> b >> c;

    if ((a != b) && (a != c) && (b != c))
        cout << "No" << endl;
    else if ((a == b) && (b == c))
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}

void _154() {
    string s, t, u;
    int a, b;
    cin >> s >> t;
    cin >> a >> b;
    cin >> u;

    if (s ==u)
        cout << a - 1 << " " << b << endl;
    else
        cout << a << " " << b - 1 << endl;
}

void _153() {
    int h, a;
    cin >> h >> a;

    // int times = h / a;
    // if (times % a == 0)
    //     cout << times << endl;
    // else
    //     cout << times + 1 << endl;
    cout << (h + a - 1) / a << endl;
}

void _152() {
    int n, m;
    cin >> n >> m;

    if (m == n)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    // _150();
    _152();
    
    return 0;
}

