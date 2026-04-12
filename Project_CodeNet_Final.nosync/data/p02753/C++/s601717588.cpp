#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>

#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define PI 3.141592653589

using namespace std;

int gcd(int a, int b){return (a % b)? gcd(b, a % b) : b;}
int lcm(int a, int b){return a * b / gcd(a, b);}

void solve_A(){
    string s;
    cin >> s;
    if(s[0] != s[1] || s[1] != s[2]) cout  << "Yes";
    else cout << "No";

}

int main(void){
    solve_A();
    
    return 0;
}