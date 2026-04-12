//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set> 

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<n;++i)
#define mod (ll)(1e9+7)
#define FIX(a) ((a)%mod+mod)%mod
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define fi first
#define se second
#define pb push_back
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    multiset<int> st;
    vint a(n);
    REP(i,n){
        cin >> a[i];
    }
    st.insert(a[0]);
    for(int i=1;i<n;i++){
        auto itr1 = st.lower_bound(a[i]);
        if(itr1==st.end()){
            auto itr2 = st.end();
            itr2--;
            st.erase(itr2);
            st.insert(a[i]);
        }else if(itr1==st.begin()){
            st.insert(a[i]);
        }else{
            itr1--;
            st.erase(itr1);
            st.insert(a[i]);
        }
    }
    
    cout << st.size() << endl;

    return 0;
}