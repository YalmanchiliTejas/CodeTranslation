#include <bits/stdc++.h>
#define endl '\n'
#define pi 3.1415926535897932384626433832
#define ll long long
using namespace std;
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / __gcd(a, b); }
bool isPrime(int n) {if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6) if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;}

void lok(){
    double d,k;
    cin>>d>>k;
    double xh=k;
    double dak=(1800-k)*(1800-k)/3600;
    xh+=dak+(1800-k/2)*k/1800;
    cout<<xh<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    if(a>=30){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
    return 0;
}