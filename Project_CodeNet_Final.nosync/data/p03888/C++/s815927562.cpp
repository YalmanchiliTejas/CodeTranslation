 #include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long long unsigned int ull;
typedef long double ld;
typedef vector<int> vr;
typedef pair<int, int> pr;
#define pb push_back
#define ff first
#define ss second
#define INF 1999999999
#define MODA 1000000007
#define PI 3.1415926535897932384626433
#define endl "\n"
//cout << fixed << setprecision(2);

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r1, r2;
    cin >> r1 >> r2;
    double sum = (double)(r1 + r2);
    double mul = (double)(r1 * r2);

    double r3 = (double)(mul / sum);
    cout << fixed << setprecision(10);
    cout << r3 << endl;
    return 0;
}

