#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

int main(){
    string s;cin>>s;
    sort(All(s));
    s.erase(unique(All(s)),s.end());
    if(s.size()==1) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
