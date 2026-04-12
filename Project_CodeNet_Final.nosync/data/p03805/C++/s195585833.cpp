#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<map>
#include<unordered_map>
#include<queue>
#include<deque>

using namespace std;
using ll=long long;
#define rep(i,n)  for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

vector<vector<int>> g(10);

bool istrue(int pos, vector<int> path){
    bool out = false;
    rep(i, g[pos].size())if(g[pos][i]==path.front())out = true;
    
    int next = path.front();
    path.erase(path.begin());

    if(!out)return false;
    else {
        if(path.empty())return true;
        else return istrue(next, path);
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> arr(n-1);
    rep(i, n-1)arr[i] = i+1;

    ll ans = 0;
    do{
        if(istrue(0, arr))ans++;
    }while(next_permutation(ALL(arr)));

    cout << ans << endl;
}