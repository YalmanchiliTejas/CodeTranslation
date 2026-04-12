#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> P;

const int INF = 1e9;
const int mod = 1e9+7;
const double EPS = 1e-10;
const double PI = acos(-1.0);

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    cout << ((a*100+b*10+c)%4 == 0 ? "YES" : "NO") << endl;

    return 0;
}