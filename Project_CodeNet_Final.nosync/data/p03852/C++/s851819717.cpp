#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using V = vector<ll>;
#define _GLIBCXX_DEBUG
#define rep(i, a, b) for(int i = a; i < b; i++)
#define ALL(v) v.begin(), v.end()

int main(){
    char c;
    cin>>c;
    vector<char> v={'a','i','u','e','o'};
    bool f=false;
    rep(i,0,5) if(c==v[i]) f=true;
    if(f) cout<<"vowel"<<endl;
    else cout<<"consonant"<<endl;
}
