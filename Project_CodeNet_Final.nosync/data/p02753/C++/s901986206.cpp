#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using V = vector<ll>;
#define _GLIBCXX_DEBUG
#define rep(i, a, b) for(int i = a; i < b; i++)
#define ALL(v) v.begin(), v.end()

int main(){
    string s;
    cin>>s;
    if(s[0]!=s[1]||s[1]!=s[2])cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
