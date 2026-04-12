#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long int ll;

int main(){
    int n; cin >> n;
    set<ll> prime;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        int cp=a[i];
        for(int j=2;j*j<=a[i];j++){
            if(cp%j!=0)continue;
            else{
                while(cp%j==0){
                    cp/=j;
                }
                prime.insert(j);
            }
        }
        if(cp!=1)prime.insert(cp);
    }
    ll ans=0;
    for(auto s:prime){
        ll cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]%s==0)cnt+=a[i];
        }
        ans=max(ans,cnt);
    }
    cout << ans << endl;
}
