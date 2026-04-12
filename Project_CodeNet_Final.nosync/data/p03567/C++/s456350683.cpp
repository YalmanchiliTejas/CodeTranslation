#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using P=pair<int,int>;
int main() {
    string s;cin>>s;
    int resu=0;
    for(int i=0;i<s.size()-1;i++){
        if(s.at(i)=='A' &&s.at(i+1)=='C') resu=1;
    }
    if(resu==1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}