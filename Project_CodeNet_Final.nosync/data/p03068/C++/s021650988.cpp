#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
int Gcd(int a,int b){if (b == 0) return a; return Gcd(b , a%b);}
int Lcm(int a, int b){ return a/Gcd(a,b)*b;}
inline int read(){
    int f = 1, x = 0;char ch = getchar();
    while (ch > '9' || ch < '0'){if (ch == '-')f = -f;ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return x * f;
}
const int maxn = 1e5 + 10;
int main(){
    int n = read();
    string s;
    cin >> s;
    int k = read();
    char ch = s[k-1];
    for(int i=0; i<n; i++){
        if (s[i] != ch){
            s[i] = '*';
        }
    }
    cout << s << endl;
    return 0;
}   