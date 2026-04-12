#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pint;

int main(){
    int r,g,b;
    cin>>r>>g>>b;
    if((r*100+g*10+b)%4==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}