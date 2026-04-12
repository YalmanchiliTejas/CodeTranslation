#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    string s;
    cin>>s;
    set<int> si;
    for(auto u : s){
        si.insert(u);
    }
    if(si.size()==2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}