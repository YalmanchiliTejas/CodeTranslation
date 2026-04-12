#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    string s;
    cin >> s;
    bool flag=false;
    rep(i,s.size()-1){
        if(s.at(i)=='A'&&s.at(i+1)=='C'){
            flag=true;
        }
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}
