#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "rt", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    fast
    string s;cin>>s;
    int a=0, b=0;
    for(int i=0; i<3; i++){
    	if(s[i]=='A'){
    		a++;
    	}else b++;
    }
    if(a==3 || b==3) cout<<"No";
    else cout<<"Yes";

#ifndef ONLINE_JUDGE
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}