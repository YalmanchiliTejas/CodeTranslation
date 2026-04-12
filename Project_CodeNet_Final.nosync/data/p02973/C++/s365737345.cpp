#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main(){
    int n;
    cin >> n;
    ll aa[100005];
    multiset<ll> a;
    for(int i = 0; i < n; i++){
        cin >> aa[i];
    }
    for(int i = n-1; i>=0; i--){
        auto itr = a.upper_bound(aa[i]);
        if(itr == a.end())a.insert(aa[i]);
        else{
            a.erase(itr);
            a.insert(aa[i]);
        }
    }
    cout << a.size() << endl;
    return 0;
}