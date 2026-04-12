#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb emplace_back
#define INF (1e9+1)

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int s = a*100+b*10+c;
    if(s%4==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
