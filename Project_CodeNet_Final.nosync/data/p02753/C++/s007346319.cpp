#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define REP(i,n) for (int i=1;i<=(n);i++)
typedef long long ll;

int main() {
    string a;
    cin >> a;
    bool ans = false;
    rep(i,a.size()-1){
        if(a.substr(i,1)!=a.substr(i+1,1)){
            ans = true;
        }
    }
    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}