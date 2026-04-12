#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    if (fopen("input.in", "r")) {
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    } 
    int x;
    cin>>x;
    cout<<((x>=30)?"Yes":"No")<<"\n";
}
