#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define PI 3.1415926535897932384626433
#define mod 1000000007

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main(){
    string s;
    cin >> s;
    bool ac = false;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if(s[i] == 'A' && s[i+1] == 'C'){
            ac = true;
        }
    }
    if(ac){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
