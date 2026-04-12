#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int q(int a,int b){
    cout << "? " << a << " " << b << endl;
    int t;
    cin >> t;
    return t;
}



int main(){
    int n,s,t;
    cin >> n >> s >> t;
    map<pair<int,int>,int >mp; 
    int dist = q(s,t);
    vector<pair<int,int> > v;
    for(int i=1;i<=n;i++){
        if(i==s||i==t)continue;
        int dsi = q(s,i);
        int dit = q(i,t);
        if(dsi+dit==dist){
            v.push_back(MP(dsi,i));
            mp[MP(s,i)] = dsi;
            mp[MP(i,t)] = dit;
        }
    }
    sort(v.begin(),v.end());
    int m = v.size();
    vector<int>res;
    res.push_back(s);
    res.push_back(v[0].second);
    int id = v[0].second;
    for(int i=1;i<m;i++){
        int next = v[i].second;
        int d = q(id,next);
        if(mp[MP(s,id)]+d == mp[MP(s,next)]){
            res.push_back(next);
            id = next;
        }
    }
    res.push_back(t);
    cout << "! ";
    for(int i=0;i<res.size();i++){
        cout << res[i];
        if(i!=res.size()-1){
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
