#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
int main(){
    int n;cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    deque<int> d;
    for(int i=0;i<n;i++){
        int p=lower_bound(d.begin(),d.end(),a[i])-d.begin();
        if(p==0){
            d.push_front(a[i]);
        }
        else d[p-1]=a[i];
    }
    cout << d.size() << endl;
    return 0;
}