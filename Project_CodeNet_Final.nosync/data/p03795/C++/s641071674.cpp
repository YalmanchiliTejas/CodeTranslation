#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;

const int INT_INF = 2147483646;
const ll LL_INF = 9223372036854775807;


const int SIZE = 1e5+100;

ll n;
int main(){
    cin >> n;
    cout << n*800 - (n/15)*200 << endl;
}