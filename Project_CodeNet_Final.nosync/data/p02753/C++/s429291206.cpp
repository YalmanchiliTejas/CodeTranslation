#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    string S; cin >> S;
    bool ans=true;
    if(S == "AAA" || S == "BBB")  ans=false;
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}