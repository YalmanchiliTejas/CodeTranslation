#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++) //for文マクロ
using namespace std;

typedef unsigned long ul;
typedef long long ll;
typedef pair<ul, ul> P; //ペア　タイプでふ

int main()
{
    int a = 0;
    cin >> a;
    cout << a * 800 - (a - a % 15) / 15 * 200;
    return 0;
}