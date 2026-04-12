#include <bits/stdc++.h>
#define ll long long
#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define sorta(V) sort(V.begin(), V.end())
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end() 

using namespace std;

int main(){

    int n,m;
    cin >> n >> m;

    vector<vector<int>> v;

    rep(i,n + 1){
        vector<int> tmpv;
        v.pback(tmpv);
    }

    rep(i,m){
        int a,b;
        cin >> a >> b;

        v[a].pback(b);
        v[b].pback(a);
    }

    queue<pair<int, set<int>>> q;
    set<int> s;

    q.push(mpair(1, s));
    int ans = 0;

    while(!q.empty()){
        int tmpn = q.front().first;
        set<int> tmps = q.front().second;

        if(tmps.size() == n - 1){

            ans++;

        }else{

            tmps.insert(tmpn);

            rep(i,v[tmpn].size()){
                int tmpto = v[tmpn][i];
                if(tmps.find(tmpto) == tmps.end()){
                    q.push(mpair(tmpto, tmps));
                }
            }

        }

        q.pop();

    }

    cout << ans << endl;

    return 0;
}