#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define MOD 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(v) (v).begin() , (v).end()
#define sumof(v) accumulate(all(v), 0LL, plus<ll>())
#define maxof(v) max_element(all(v))
#define minof(v) min_element(all(v))
#define inf INT_MAX

int main(){
    FASTIO
    int x; cin>>x;
    if(x>=30) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}