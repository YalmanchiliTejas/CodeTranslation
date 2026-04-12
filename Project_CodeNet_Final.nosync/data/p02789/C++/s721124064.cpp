#include<bits/stdc++.h>
using namespace std;

int n, m;
string ans;

void in();
void solve();
void out();

int main(){
    in();
    solve();
    out();
}

void in(){
    cin >> n >> m;
}

void solve(){
    ans = "No";
    if(n == m)
        ans = "Yes";
}

void out(){
    cout << ans;
}
