#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<utility>
#include<functional>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;

ll N;
ll a[200010]={};
multiset<ll> st;
int main(){
    cin>>N;
    ll ans=0;
    for(int i=1;i<=N;i++){
        cin>>a[i];
        auto it=st.lower_bound(a[i]);
        if(it==st.begin()){
            ans++;
        }else{
            it--;
            st.erase(it);
        }
        st.insert(a[i]);
    }
    cout<<ans<<endl;

    return 0;
}