#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define PI 3.141592653589

using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);

void solve_A(){
    int n, m;
    cin >> n >> m;

    if(n <= m) cout << "Yes";
    else cout << "No";
}

void solve_B(){
    
}

void solve_C(){
    
}

int main(void){
    solve_A();
    solve_B();
    solve_C();
    
    return 0;
}

int gcd(int a, int b){
    if(a < b) swap(a, b);

    int r = a % b;
    while(r != 0){
        a = b;  b = r;  r = a % b;
    }
    return b;
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}