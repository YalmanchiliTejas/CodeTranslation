#include <bits/stdc++.h>

using namespace std;
#define ll long long int
const int MAXN = 2 * 1e5 + 5;

void solve(){
    string s; cin >> s;
    bool p1 = false, p2 = false;
    for(auto & x: s){
        if( x == 'A')
            p1 = true;
        else
            p2 = true;
    }   
    if( p1 and p2)
        cout << "Yes\n";
    else 
        cout << "No\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
	//int t; cin >> t;
	//while(t--)
		solve();
}





