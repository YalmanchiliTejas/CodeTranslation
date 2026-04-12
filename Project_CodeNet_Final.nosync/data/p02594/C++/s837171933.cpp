#include<bits/stdc++.h>
using namespace std;
#define INFTY 1<<20
#define rep(i,n) for (ll i = 0; i < (n); ++i)
typedef long long int ll;
using ipair = pair<int,int>;
bool operator< (const ipair a, const ipair b){return a.first < b.first;};
const int MOD=1000000007;

int main(){  
    int x; cin>>x;
    if(x>=30)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}