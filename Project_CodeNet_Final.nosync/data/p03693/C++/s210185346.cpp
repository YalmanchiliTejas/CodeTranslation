 #include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 1999999999
#define MODA 1000000007

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b, c;
    cin >> a >> b >> c;
    string sum = a + b + c;
    int s = stoi(sum);
    if(s%4 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;



    return 0;
}
