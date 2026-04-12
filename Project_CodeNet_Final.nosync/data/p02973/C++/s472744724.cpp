#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N;
    cin >> N;
    vector<int> V(N);
    rep(i,0,N)cin >> V[i];
    multiset<int> st;
    map<int,int> mp;
    rep(i,0,N){
        /*
        auto itr = st.lower_bound(V[i]);
        if(itr == st.begin()){
            st.insert(V[i]);
            continue;
        }
        itr--;
        auto itr2 = st.find(*itr);
        itr2 = V[i];
        */
        auto itr = mp.lower_bound(V[i]);
        if(itr == mp.begin()){
            mp[V[i]]++;
            continue;
        }
        itr--;
        int x = itr->second;
        if(x == 1){
            mp.erase(itr);
        }else{
            mp[itr->first]--;
        }
        mp[V[i]]++;
    }
    int sum = 0;
    for(auto p:mp){
        sum += p.second;
    }
    cout << sum << endl;
}