#pragma region Header
#define _CRT_SECURE_NO_WARNINGS
#define FOR(i,s, e) for(int i = s; i<e; ++i)
#define rFOR(i,s, e) for(int i=s-1; i>=e; --i)
#define loop(len) for(int i=0; i<len; ++i)
#define rloop(len) for(int i=len-1; i>=0; --i)
#define iPair pair<int,int>
#define LPair pair<ll,ll>
#define vecP(t,t2) vector<pair<t,t2>>
#define uoMP(t, t2) unordered_map<t, t2>
#define pb push_back
#define pp pop_back
#define beg_end(v) v.begin(), v.end()
#define Sort(v) sort(v.begin(), v.end())
#define rSort(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.begin(), v.end())
#define MrN ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
typedef long long  ll;
typedef long double  ld;
#include<bits/stdc++.h>
using namespace std;
#pragma endregion

int n, m, ans;
vector<vector<int>> ver;

void DFS(int node, set<int> Set){
    
    Set.erase(node);

    loop(ver[node].size()){
        int cur = ver[node][i];
        
        if(Set.count(cur)){
            DFS(cur, Set);
        }
    }

    if(Set.size() == 0)
        ans++;
}

int main(){
    MrN;
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    ver.resize(n+1);
    loop(m){
        int a, b;
        cin >> a >> b;
        ver[a].pb(b);
        ver[b].pb(a);
    }

    set<int> s;
    loop(n){
        s.insert(i+1);
    }

    DFS(1, s);
    
    cout << ans << '\n';

    return 0;
}
