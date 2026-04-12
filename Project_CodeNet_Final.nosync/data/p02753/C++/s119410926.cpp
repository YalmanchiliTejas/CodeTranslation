#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;


void solve(){
    string s;
    cin >> s;
    int a =0, b = 0;
    for(int i = 0 ; i < s.size(); i++){
        if(s[i] == 'A') a++;
        if(s[i] == 'B') b++;
    }
    if(a && b)
        cout << "Yes\n";
    else
        cout << "No\n";

}


int main(){
    //int t; cin >> t;
    //while(t--) solve();
    solve();
    return 0;
}
