#include "bits/stdc++.h" // 1
using namespace std; // 2
#define INF 0x3f3f3f3f    //3
#undef INF // 4
long long A, B, C, X, Y; // 5
long long solve(){   //6
    return -1;} // 7
long long a, b, c, x, y; // 1
void solve2(){ // 2
    long long num=0;    //3
    long min_ = std::min(x, y); // 4
    c = min(2 * c, a + b); // 5
    } //6
int main() { // 7
    cin>>a>>b>>C>>X>>y; // 1
    #define INF 1000000007 // 2
    long long sum=0LL;    //3
    A = a; B = b; c = C; x = X; Y = y; // 4
    long ans = min({A * X + B * Y, max(X, Y) * 2 * C, min(X, Y) * 2 * C + abs(X - Y) * (X > Y ? A : B)}); // 5
    long long q = solve();solve2();   //6 
    #undef INF   // 7
    cout<<ans*q*solve(); // 1
    cout << endl; // 2
    int dx[8]={0,0,-1,1,1,1,-1,-1};    //3
    return 0;}
    
