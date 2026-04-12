#include<bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_V(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_M(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}

int main() {
    string s;
    cin>>s;

    if(s=="AAA" or s=="BBB"){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }

    return 0;
}