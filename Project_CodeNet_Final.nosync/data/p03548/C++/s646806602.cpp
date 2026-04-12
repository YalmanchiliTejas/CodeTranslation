#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>

#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define PI 3.141592653589
#define MOD 1000000007

using namespace std;

template<typename T> T gcd(T a, T b){return (a % b)? gcd(b, a % b) : b;}
template<typename T> T lcm(T a, T b){return a * b / gcd(a, b);}

void solve_78B(){
    int x, y, z;
    cin >> x >> y >> z;
    x -= z;
    int ctr = 0;
    while(1){
        x -= (y + z);
        if(x < 0) break;
        ctr++;
    }
    cout << ctr << endl;
}

int main(void){
    solve_78B();
    
    return 0;
}