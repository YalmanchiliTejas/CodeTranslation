
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    map<string,bool>p;
    p.insert(pair<string,bool>("BBB",true));
    p.insert(pair<string,bool>("AAA",true));
    if(p[s]) cout<<"No\n";
    else cout<<"Yes\n";
    return 0;
}
