#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int INF = 1e9;
int MOD = 1e9+7;
main(){
    int a,b,c,d = 0;
    cin >> a >> b >> c;
    d = a*100+b*10+c;
    if(d % 4 == 0)cout << "YES" << endl;
    else cout << "NO" << endl;
}