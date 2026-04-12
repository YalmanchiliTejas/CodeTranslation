#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++) //for文マクロ
using namespace std;

typedef unsigned long ul;
typedef long long ll;
typedef pair<ul, ul> P; //ペア　タイプでふ

int main()
{
    char a;
    cin >> a;
    if (a == 'a' || a == 'i' || a == 'u' || a == 'o' || a == 'e')
    {
        cout << "vowel";
    }
    else
    {
        cout << "consonant";
    }
}
