#include <bits/stdc++.h>
using namespace std;
#define repr(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
#define mod 1000000007

ll gcd(ll x,ll y) {return y ? gcd(y,x%y) : x;} 
ll lcm(ll x,ll y) {return x/gcd(x,y)*y;}

int main(){
    int n,k;
    string s;
    cin >> n >> s >> k;
    char c=s[k-1];
    for(int i=0;i<n;i++){
        if(s[i]==c) cout << c;
        else cout << '*';
    }
    cout << endl;
    return 0;
}









