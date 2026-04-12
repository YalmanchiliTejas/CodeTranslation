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

class UnionFindTree
{
private:
    int n;
    int groupNum;       // ??°??????????????°
    vector<int> parent; // ????????????
    vector<int> rank;   // ??¨??????????????????
    vector<int> num;    // ??°????????????????´???°
    int find(int i){
        if(parent[i] == i)
            return i;
        else
            return parent[i] = find(parent[i]);
    }
public:
    UnionFindTree(int n){ // ?????????????????????
        this->n = n;
        groupNum = n;
        parent.resize(n);
        for(int i=0; i<n; ++i)
            parent[i] = i;
        rank.assign(n, 0);
        num.assign(n, 1);
    }
    void unite(int a, int b){ // a??¨b?????°??????????????????
        if((a = find(a)) != (b = find(b))){
            if(rank[a] < rank[b]){
                parent[a] = b;
                num[b] += num[a];
            }
            else{
                parent[b] = a;
                if(rank[a] == rank[b])
                    ++ rank[a];
                num[a] += num[b];
            }
            -- groupNum;
        }
    }
    bool same(int a, int b){ // a??¨b?????°?????????????????????????????????
        return find(a) == find(b);
    }
    int getNum(){ // ??°??????????????°?????????
        return groupNum;
    }
    int getNum(int a){ // a?????°????????????????´???°?????????
        return num[find(a)];
    }
    void getGroup(vector<vector<int> >& group){ // ??°??????????§?????????????
        map<int, int> index;
        group.clear();
        for(int i=0; i<n; ++i){
            int a = find(i);
            if(index.find(a) == index.end()){
                index[a] = group.size();
                group.resize(group.size() + 1);
            }
            group[index[a]].push_back(i);
        }
    }
};

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
    Mod& operator/=(const Mod& x){ // ?????§?????????????°??????????MOD????´???°??§????????´???????????????
        int b = MOD - 2;
        long long c = x.a;
        while(b > 0){
            if(b & 1){
                a *= c;
                a %= MOD;
            }
            c *= c;
            c %= MOD;
            b >>= 1;
        }
        return *this;
    }
    bool operator==(const Mod& x) const{
        return a == x.a;
    }
    long long getValue(){
        return a;
    }
};

// ?????????????¨??????????
Mod determinant(vector<vector<Mod> > mat)
{
    const int n = mat.size();
    Mod ret = 1;
    for(int i=0; i<n; ++i){
        int tmp = -1;
        for(int j=i; j<n; ++j){
            if(mat[j][i] != 0){
                tmp = j;
                break;
            }
        }
        if(tmp == -1)
            return 0;
        if(tmp != i){
            mat[i].swap(mat[tmp]);
            ret *= -1;
        }

        for(int j=i+1; j<n; ++j){
            for(int k=n-1; k>=i; --k){
                mat[j][k] -= mat[i][k] * (mat[j][i] / mat[i][i]);
            }
        }
        ret *= mat[i][i];
    }
    return ret;
}

/***************************************************************************************************/
// ????????¨??????
//     ??????????????¢??????????????¨????????¨?????¨????????°????±???????
//
// graph : ????????°??????
/***************************************************************************************************/
Mod MatrixTreeTheorem(const vector<vector<int> >& graph)
{
    int n = graph.size();
    vector<vector<Mod> > mat(n-1, vector<Mod>(n-1, 0));
    for(int i=0; i<n-1; ++i){
        for(int j=0; j<n-1; ++j){
            mat[i][j] = -graph[i][j];
            if(i == j)
                mat[i][j] += accumulate(graph[i].begin(), graph[i].end(), Mod(0));
        }
    }
    return determinant(mat);
}

pair<int, int> solve(int n, const vector<tuple<int, int, int> >& edges)
{
    int m = edges.size();
    UnionFindTree uft(n);
    int dMax;
    for(int i=0; ; ++i){
        int d, s, t;
        tie(d, s, t) = edges[i];
        uft.unite(s, t);
        if(uft.getNum() == 1){
            dMax = d;
            break;
        }
    }

    uft = UnionFindTree(n);
    for(int i=0; i<m; ++i){
        int d, s, t;
        tie(d, s, t) = edges[i];
        if(d < dMax)
            uft.unite(s, t);
    }
    vector<vector<int> > group;
    uft.getGroup(group);

    int x = group.size();
    Mod ans = 0;
    for(int i=1; i<(1<<(x-1)); ++i){
        bitset<32> bs(i);
        vector<vector<int> > v(2);
        for(int j=0; j<x; ++j){
            int k = (bs[j] ? 0 : 1);
            copy(group[j].begin(), group[j].end(), back_inserter(v[k]));
        }

        Mod tmp = 1;
        for(int j=0; j<2; ++j){
            int y = v[j].size();
            vector<int> index(n, -1);
            for(int k=0; k<y; ++k)
                index[v[j][k]] = k;

            vector<vector<int> > graph(y, vector<int>(y, 0));
            for(int k=0; k<m; ++k){
                int d, s, t;
                tie(d, s, t) = edges[k];
                if(index[s] != -1 && index[t] != -1){
                    ++ graph[index[s]][index[t]];
                    ++ graph[index[t]][index[s]];
                }
            }
            tmp *= MatrixTreeTheorem(graph);
        }
        ans += tmp;
    }
    ans *= 2;

    return make_pair(dMax, (int)ans.getValue());
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int> > edges(m);
    for(int i=0; i<m; ++i){
        int s, t, d;
        cin >> s >> t >> d;
        -- s;
        -- t;
        edges[i] = make_tuple(d, s, t);
    }
    sort(edges.begin(), edges.end());

    pair<int, int> ans = solve(n, edges);
    cout << ans.first << ' ' << ans.second << endl;

    return 0;
}