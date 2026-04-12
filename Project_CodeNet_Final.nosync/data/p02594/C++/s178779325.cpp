#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL); 

    #ifndef ONLINE_JUDGE 
        freopen("__input.txt", "r", stdin); 
        freopen("__output.txt", "w", stdout); 
    #endif 

    ll t;
    cin >> t;

    if(t >= 30) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}