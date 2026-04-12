//#pragma GCC optimize "trapv"
#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand rng
#define fios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define M_PI 3.14159265358979323846
typedef long long ll;



int main() {
    //fios;
    
    int x;
    cin >> x;
    if(x >= 30) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}