#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
bool isPrime(int x){
    int i;
    if(x < 2)return 0;
    else if(x == 2) return 1;
    if(x%2 == 0) return 0;
    for(i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
    return 1;
}
int digsum(int n) {
    int res = 0;
    while(n > 0) {
        res += n%10;
        n /= 10;
    }
    return res;
}
int stringcount(string s, char c) {
    return count(s.cbegin(), s.cend(), c);
}

int main(void){
    string S;
    cin >> S;
    if(S[0]==S[1]&&S[1]==S[2])cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
    
}
