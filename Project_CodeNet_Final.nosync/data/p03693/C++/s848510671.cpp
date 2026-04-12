#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll r,g,b;cin>>r>>g>>b;
    ll n = r*100+g*10+b;
    cout<<(n%4?"NO":"YES");
}
