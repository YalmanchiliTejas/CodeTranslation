#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int n;


int main(){
    cin>>n;
    multiset<int> m;

    rep(i,n){
        int x;
        cin>>x;
        auto it=m.lower_bound(x);
        if(it!=m.begin()) m.erase(--it);
        m.insert(x);
    }

    cout<<m.size()<<endl;
}