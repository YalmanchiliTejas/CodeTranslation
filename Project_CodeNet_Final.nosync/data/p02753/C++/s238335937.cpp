#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
ll n;
int main(){
    string s;
    cin>>s;
    int a=0,b=0,c=0;
    for(int i = 0;i < s.size(); i++){
        if( s[i] == 'A' ) a++;
        if( s[i] == 'B')  b++;
    }
    if(a>0 && b>0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}