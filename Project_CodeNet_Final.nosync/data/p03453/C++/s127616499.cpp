#include<bits/stdc++.h>
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vpii         vector<pair<int,int>>
#define gph          map<int, vector<int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define FORS(i, n) for(; i < (int)(n); i++)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define printArr(A,n) { cout << #A << " = "; FOR(i,n) cout << A[i] << ' '; cout << endl; }
using namespace std;
#define int long long int
const int MOD = (int)1e9 + 7;
int s, t;
vector<vector<pii>> adjList((int)2e5);
void solve(int cur,  vi& dis, vi& way){
    priority_queue<pair<int, pii> , vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    pq.push(mp(0, mp(cur, cur)));
    way[cur] = 1;
    while(!pq.empty()){
        pair<int,pii> temp = pq.top();
        cur = temp.second.first;
        pq.pop();
        if(dis[cur] == -1){
            dis[cur] = temp.first;
            way[cur] = way[temp.second.second];
            assert(way[cur] >= 0);
            for(pii child: adjList[cur]){
                pq.push(mp(child.second + temp.first, mp(child.first, cur)));
            }
        }else if(dis[cur] == temp.first){
            way[cur] += way[temp.second.second];
            assert(way[cur] >= 0);
            way[cur] %= MOD;
        }
    }
}

vi dis((int)2e5, -1), dis2((int)2e5, -1), way((int)2e5), way2((int)2e5);
vector<bool> visit((int)(2e5));
int ans = 0;
int cnt = 0;
int sqr(int temp){
    int a = temp * temp;
    a  %= MOD;
    return a;
}
void count(int cur){
    stack<int> s;
    s.push(cur);
    int cnt = 0, cnt1 = 0;
    ans = 0;
    while(!s.empty()){
        cur = s.top(); s.pop();
        if(visit[cur])continue;
        visit[cur] =true;
        //check if they can meet 
        //at this vertex
        if(dis[cur]*2 == dis[t] && dis2[cur]*2 == dis[t]){
            cnt++;
            ans += sqr(way[cur]) * sqr(way2[cur]); 
            ans %= MOD;
        }
        //at an edge from this vertex
        for(pii child: adjList[cur]){
            int c= child.first;
            if(dis[cur]*2 < dis[t] && dis[cur] + dis2[child.first] + child.second == dis[t] && dis[child.first]*2 > dis[t]){
                cnt1++;
                ans += sqr(way[cur]) * sqr(way2[child.first]);
                ans %= MOD;
            }
        }
        for(pii child: adjList[cur])s.push(child.first);

    }
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

  //  freopen("08.txt", "r", stdin);

    int n,m;cin >> n >> m;
    cin >> s >> t;
    s--, t--;
    int u, v, d;
    dis = vector<int>(n, -1);
    dis2 = vector<int>(n, -1);
    FOR(i, m){
        cin >> u >> v >> d;
        u--, v--;
        adjList[u].pb(mp(v, d));
        adjList[v].pb(mp(u, d));
    }
    solve(s,  dis, way);
    solve(t, dis2, way2);

    count(s);

    //    FOR(i, n)cout << i+ 1 << " " << way[i] << " " << dis[i] << endl;
//    debug(way[t]);
 //   debug(ans);
    int temp=  way[t]*way[t];
    temp %= MOD;
    temp -= ans;
    temp %= MOD;
    if(temp <0 )temp += MOD;
    cout << temp;
}


