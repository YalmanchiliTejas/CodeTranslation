//It's like the first time I realized that
//All You Need Is Love



#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.2")

#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()

inline void opting() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

long long inp() {
    long long x;
    cin >> x;
    return x;
}

void make_unique(vector<long long> &vec, bool sorted = false) {
    if(!sorted)
        sort(all(vec));
    vec.resize(unique(all(vec)) - vec.begin());
}
const long long SQRT = 450, lg = 18 + 2, inlim = 2147483647;
const long long maxn = 2e5 + 69, delta = 1e9 + 7, inf = 1e17 + 420;


long long n, m, st, en;

vector<pair<long long, long long>> adj[maxn];
void add_edge(long long u, long long v, long long w){
    adj[v].push_back(make_pair(u, w));
    adj[u].push_back(make_pair(v, w));
}

vector<long long> dist_st, dist_en;
vector<long long> st_cnt, en_cnt;

void initiate(){
    for(long long i = 0; i < n; i++){
        dist_st.push_back(inf);
        dist_en.push_back(inf);

        st_cnt.push_back(0);
        en_cnt.push_back(0);
    }
}

void input(){
    cin >> n >> m >> st >> en;
    st--, en--;
    initiate();
    for(long long i =0; i < m; i++){
        long long u, v, w;
        cin >> u >> v >> w;
        add_edge(u - 1, v - 1, w);
    }

}
//___________________________________________________

bool mark[maxn];
void DJ_kestra(vector<long long> &dist, vector<long long> &cnt, long long v){
    memset(mark, 0, sizeof mark);
    set<pair<long long, long long> > S;
    S.insert(make_pair(0, v));

    dist[v] = 0;
    cnt[v] = 1;

    while(!S.empty()){
        pair<long long, long long> p = *(S.begin());
        S.erase(p);
        if(mark[p.second])
            continue;

        mark[p.second] = true;
        long long d = p.first;
        v = p.second;
        //cout <<"at "<<1 + v << ' '<<dist[v]<<' ' << cnt[v]<<endl;

        for(auto u : adj[v]){

            if(dist[u.first] > d + u.second){
                S.insert(make_pair(d + u.second, u.first));
                cnt[u.first] = 0;
            }

            dist[u.first] = min(dist[u.first], d + u.second);
            if(dist[u.first] == d + u.second)
                cnt[u.first] = (cnt[u.first] + cnt[v]) % delta;
        }
    }
}
//____________________________________________________________

long long p2(long long x){
    x %= delta;
    return (x * x) % delta;
}

void solve(){
    DJ_kestra(dist_st, st_cnt, st);
    DJ_kestra(dist_en, en_cnt, en);

    long long D = dist_st[en];
    long long C = p2(st_cnt[en]);
    long long denum = 0;

    //cout << D << ' ' << C << endl;

    for(long long i = 0; i < n; i++){
        if(dist_st[i] + dist_en[i] == D and dist_en[i] == dist_st[i])
            denum = (denum + p2(st_cnt[i] * en_cnt[i])) % delta;
        else
            for(auto u : adj[i])
                if(dist_st[i] + u.second > dist_en[u.first] and
                   dist_st[i] < u.second + dist_en[u.first] and
                   dist_st[i] + u.second + dist_en[u.first] == D)
                        denum = (denum + p2(st_cnt[i] * en_cnt[u.first]) ) % delta;
    }
    cout << (delta + C - denum) %delta << endl;
}

int main() {
    opting();
    //file_edit();

    input();
    solve();

}
