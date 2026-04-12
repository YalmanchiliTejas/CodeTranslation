#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
int main() {
//freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int a, b, c;
    cin >> a >> b>> c;
    int s = a*100+b*10+c;
    if(s%4 == 0) cout <<"YES" << endl;
    else cout << "NO"<< endl;
    return 0;
}