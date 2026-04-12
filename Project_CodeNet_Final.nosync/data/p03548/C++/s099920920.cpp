#include <bits/stdc++.h>
#define rep(i,n) for(long long int i = 0; i < n; i++)
#define print(n) std::cout << n << std::endl
#define _print(n) std::cout << n
using namespace std;
typedef long long ll;
const int N = 1000000;

int main() {
    int x,y,z; cin >> x >> y >> z;
    int sum = 0;
    int hito = 0;

    while (sum < x - z){
        sum += y + z;
        hito++;
    }
    if(sum <= x - z)print(hito);
    else print( hito - 1);
}