#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5;
const int INF = 1e9;



int main() {
    char c;
    cin >> c;
    char arr[] = {'a', 'e', 'i', 'o', 'u'};
    for (char z : arr)
        if (c == z)
            cout << "vowel", exit(0);
    cout << "consonant";
}

