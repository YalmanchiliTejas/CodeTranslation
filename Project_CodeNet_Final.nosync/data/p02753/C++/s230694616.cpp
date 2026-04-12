#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    string s;
    cin >> s;
    bool flag;
    flag = true;
    rep(i,s.size()){
        if(s[0]!=s[i]) flag=false;
    }
    if (!flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}