#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <map>
// #include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())

int gcd(int a, int b){
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a * b / gcd(a,b);
}

void solve(){
    int n;
    cin >> n;

    if (n == 3 || n == 5 || n == 7) {
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }


    return;
}

int main(int argc, char const* argv[])
{
    solve();
    return 0;
}
