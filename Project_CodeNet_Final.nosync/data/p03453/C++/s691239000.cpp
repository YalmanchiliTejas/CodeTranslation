#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
using namespace std;

template <class T1>
class Operators
{
public:
    template <class T2>
    const T1 operator+(const T2& right) const{
        T1 ans = static_cast<const T1&>( *this );
        ans += right;
        return ans;
    }
    template <class T2>
    const T1 operator-(const T2& right) const{
        T1 ans = static_cast<const T1&>( *this );
        ans -= right;
        return ans;
    }
    template <class T2>
    const T1 operator*(const T2& right) const{
        T1 ans = static_cast<const T1&>( *this );
        ans *= right;
        return ans;
    }
    template <class T2>
    const T1 operator/(const T2& right) const{
        T1 ans = static_cast<const T1&>( *this );
        ans /= right;
        return ans;
    }
    bool operator!=(const T1& right) const{
        const T1& left = static_cast<const T1&>( *this );
        return !(left == right);
    }
    bool operator>(const T1& right) const{
        const T1& left = static_cast<const T1&>( *this );
        return right < left;
    }
    bool operator<=(const T1& right) const{
        const T1& left = static_cast<const T1&>( *this );
        return !(right < left);
    }
    bool operator>=(const T1& right) const{
        const T1& left = static_cast<const T1&>( *this );
        return !(left < right);
    }
};

class Mod : public Operators<Mod>
{
private:
    static const int MOD = 1000000007;
    long long a;
public:
    Mod(){
        a = 0;
    }
    Mod(long long x){
        a = (x % MOD + MOD) % MOD;
    }
    Mod& operator+=(const Mod& x){
        a = (a + x.a) % MOD;
        return *this;
    }
    Mod& operator-=(const Mod& x){
        a = (a - x.a + MOD) % MOD;
        return *this;
    }
    Mod& operator*=(const Mod& x){
        a = (a * x.a) % MOD;
        return *this;
    }
    bool operator==(const Mod& x) const{
        return a == x.a;
    }
    long long getValue(){
        return a;
    }
};

template <class T>
class EdgeBase
{
public:
    int to;
    T cost;
    EdgeBase(){};
    EdgeBase(int to0, T cost0){to = to0; cost = cost0;}
};
typedef EdgeBase<long long> Edge;

template<class T>
void shortestPath(const vector<vector<EdgeBase<T> > >& edges, int start, vector<T>& dist)
{
    const T INF = numeric_limits<T>::max();
    const T EPS = static_cast<T>(1.0e-10);

    dist.assign(edges.size(), INF);
    dist[start] = 0;
    priority_queue<pair<T,int>, vector<pair<T,int> >, greater<pair<T,int> > > q;
    q.push(make_pair(0, start));

    while(!q.empty()){
        pair<T, int> p = q.top();
        q.pop();
        int v = p.second;
        if(dist[v] < p.first - EPS)
            continue;
        for(unsigned i=0; i<edges[v].size(); ++i){
            EdgeBase<T> e = edges[v][i];
            if(dist[v] + e.cost < dist[e.to] - EPS){
                dist[e.to] = dist[v] + e.cost;
                q.push(make_pair(dist[e.to], e.to));
            }
        }
    }
}

void solve(const vector<vector<Edge> >& edges, int s, int t, vector<long long>& dist, vector<Mod>& cnt)
{
    shortestPath(edges, s, dist);

    int n = edges.size();
    vector<pair<long long, int> > v(n);
    for(int i=0; i<n; ++i)
        v[i] = make_pair(dist[i], i);
    sort(v.rbegin(), v.rend());

    cnt.assign(n, 0);
    cnt[t] = 1;
    for(int i=0; i<n; ++i){
        int a = v[i].second;
        for(const Edge& e : edges[a]){
            int b = e.to;
            if(dist[a] - e.cost == dist[b])
                cnt[b] += cnt[a];
        }
    }
}

int main()
{
    int n, m, start, goal;
    cin >> n >> m >> start >> goal;
    -- start;
    -- goal;

    vector<vector<Edge> > edges(n);
    for(int i=0; i<m; ++i){
        int u, v, d;
        cin >> u >> v >> d;
        -- u;
        -- v;
        edges[u].push_back(Edge(v, d));
        edges[v].push_back(Edge(u, d));
    }

    vector<long long> dist, dist2;
    vector<Mod> cntStart, cntGoal;
    solve(edges, start, goal, dist, cntGoal);
    solve(edges, goal, start, dist2, cntStart);

    Mod ans = cntStart[goal] * cntGoal[start];
    for(int a=0; a<n; ++a){
        if(dist[a] * 2 == dist[goal]){
            Mod tmp = cntStart[a] * cntGoal[a];
            tmp *= tmp;
            ans -= tmp;
        }
        else if(dist[a] * 2 < dist[goal]){
            for(const Edge& e : edges[a]){
                int b = e.to;
                if(dist[a] + e.cost == dist[b] && dist[b] * 2 > dist[goal]){
                    Mod tmp = cntStart[a] * cntGoal[b];
                    tmp *= tmp;
                    ans -= tmp;
                }
            }
        }
    }
    cout << ans.getValue() << endl;

    return 0;
}
