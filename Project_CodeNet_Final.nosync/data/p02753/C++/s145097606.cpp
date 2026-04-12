#include <bits/stdc++.h>
using namespace std;
#define rep(shoki,i,n) for(int i=shoki; i<n; i++)
#define _GLIBCXX_DEBUG
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vector<int>>;

int main(){
    string s; cin>>s;
    if(s[0]==s[1] && s[1]==s[2]){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}
