#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    
    if((b*10+c)%4==0) cout << "YES";
    else cout << "NO";
}