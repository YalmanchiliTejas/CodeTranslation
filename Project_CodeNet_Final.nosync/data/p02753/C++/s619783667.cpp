/**
 *    author: gxfireball       
**/
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
using namespace std;

void solve(){
   string str;
   cin >> str;
   if(str == "AAA" || str == "BBB") cout << "No";
   else cout << "Yes";
}

int main(){
    fastio;
    int t;
    t = 1;
    //cin>>t;
    while(t--){
    	solve();
    }
    return 0;
}

