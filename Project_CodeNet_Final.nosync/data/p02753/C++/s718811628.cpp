#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
    string s;
    cin >> s;
    bool a = false;
    bool b = false;
    for(int i=0;i<3;++i){
        if(s[i] == 'A'){
            a=true;
        }
        else{
            b=true;
        }
    }
    if(a&&b){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}