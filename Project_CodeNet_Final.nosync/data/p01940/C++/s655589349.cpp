#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int main(){
    string t,p;
    cin>>t>>p;
    int n=t.size(),m=p.size();
    int cur=0;
    rep(i,n){
        if(cur<m&&t[i]==p[cur]) ++cur;
        else if(t[i]==p[cur-1]){
            cout<<"no"<<endl;
            return 0;
        }
    }
    if(cur==m)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}
