#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long int i=0;i<(n);++i)
typedef long long int ll;

int main(){

    string s;
    cin >> s;

    bool f=false;

    rep(i,2){
        if(s[i]!=s[i+1]){
            f=true;
        }
    }

    if(f){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}