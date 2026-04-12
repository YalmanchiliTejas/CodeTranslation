#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<int, int> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}


int main(){

    string s;
    cin >> s;
    if(s=="AAA"||s=="BBB"){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }

    return 0;
}  