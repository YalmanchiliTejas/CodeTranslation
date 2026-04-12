#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MOD 1000000007
#define PI 3.141592653589793

int main(){
    int r, g, b;
    cin >> r >> g >> b;
    cout << ((g*10 + b) % 4 ? "NO":"YES") << endl;
}
