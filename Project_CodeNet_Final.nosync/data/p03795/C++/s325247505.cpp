#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using P = pair<int, int>;

#define roop(i, n) for(int i = 0;i < n;i++)

int main(void){

    int n;
    cin >> n;

    int plus = (n / 15) * 200;

    int ans = 800 * n - plus;

    cout << ans << endl;



    return 0;
}