#include <bits/stdc++.h>
#define int long long
#define rep(i, n) REP(i, 0, n)
#define REP(i, l, r) for (int i = l; i < r; i++)
#ifdef DEBUG
#define dout cout
#else
std::stringstream dout;
#endif
#define MOD (int)(1e9+7)
using namespace std;
typedef pair<int, int> P;
struct edge {
    int to, cost;
};

class dijkstra {
private:
    int V;
    int d[100002];
    priority_queue<P, vector<P>, greater<>> que;

public:
    dijkstra(int v, int s, vector<edge> G[]) {
        V = v;
        update(s, G);
    }

    void update(int s, vector<edge> G[]) {
        fill(d, d + V + 1, 100000000000ll);
        d[s] = 0;
        que.push(make_pair(0, s));
        while (!que.empty()) {
            P p = que.top();
            que.pop();
            int v = p.second;
            if (d[v] < p.first)
                continue;
            rep(i, G[v].size()) {
                edge e = G[v][i];
                if (d[e.to] > d[v] + e.cost) {
                    d[e.to] = d[v] + e.cost;
                    que.push(make_pair(d[e.to], e.to));
                }
            }
        }
    }

    int find(int e) {
        return d[e];
    }
};

int gcd(int a, int b) {
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

bool prime(int a) {
    if (a == 1)
        return false;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0)
            return false;
    }
    return true;
}

class Union_Find {
private:
    vector<int> t, s;

public:
    Union_Find(int max_length) {
        rep(i, max_length + 1) {
            t.push_back(i);
            s.push_back(1);
        }
    }

    void Union(int x, int y) {
        if (same(x, y))
            return;
        int tx = Find(x), ty = Find(y);
        if (s[tx] < s[ty]) {
            s[ty] += s[tx];
            t[tx] = ty;
        } else if (s[tx] > s[ty]) {
            s[tx] += s[ty];
            t[ty] = tx;
        } else if (tx > ty) {
            t[tx] = ty;
            s[ty] += s[tx];
        } else {
            t[ty] = tx;
            s[tx] += s[ty];
        }
    }

    int Find(int n) {
        if (t[n] == n)
            return n;
        else
            return t[n] = Find(t[n]);
    }

    bool same(int x, int y) {
        return Find(x) == Find(y);
    }

    int get_Size(int a) {
        return s[a];
    }
};

set<int> prime_num_factor(int n){
    if(n<2)return set<int>();
    set<int> prime;
    prime.insert(2);
    for(int i=3;i<=n;i++){
        for(int it:prime){
            if(it*it>i){
                prime.insert(i);
                break;
            }
            if(i%it==0)break;
        }
    }
    return prime;
}
vector<int> primeFactorization(int n) {
    vector<int> re;
    int cnt = 2;
    while (n != 1) {
        if (n % cnt != 0) {
            cnt++;
            continue;
        }
        n /= cnt;
        re.push_back(cnt);
    }
    return re;
}
signed main() {
    int n,cnt=0;
    cin>>n;
    deque<int>a(n);
    rep(i,n)cin>>a[i];
    int ans=1;
    REP(i,1,n){
        if(lower_bound(a.begin(),a.begin()+i-cnt,a[i-cnt])==a.begin()){
            ans++;
            a.push_front(a[i-cnt]);
            a.erase(a.begin()+i-cnt+1);
        }
        else {
            dout<<i-cnt<<endl;
            *(lower_bound(a.begin(),a.begin()+i-cnt,a[i-cnt])-1)=a[i-cnt];
            a.erase(a.begin()+i-cnt);
            cnt++;
        }
    }
    cout<<ans<<endl;
}
