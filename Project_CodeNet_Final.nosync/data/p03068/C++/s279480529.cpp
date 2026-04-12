/* おまじない　*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
typedef long long ll;
typedef long double ld;
using namespace std;
const ll MOD=pow(10,9)+7;
const ll INF=(1LL<<62);
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int ddx[8]={1,0,-1,-1,-1,0,1,1};
const int ddy[8]={1,1,1,0,-1,-1,-1,0};
void init(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main(){
    init();
    ll N;cin>>N;
    string s;cin>>s;ll K;cin>>K;K--;
    for(int i=0;i<N;i++){
        if(s[K]==s[i])cout<<s[i];
        else cout<<'*';
    }
    cout<<endl;



}