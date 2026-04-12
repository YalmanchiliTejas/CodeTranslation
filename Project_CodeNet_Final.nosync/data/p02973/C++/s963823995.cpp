#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <bitset>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
 
using namespace std;
 
#define R 1000000007
#define M 998244353
#define grid vector<vector<long long>>
#define L 256

long long mx = INT32_MIN, mn = INT32_MAX;

struct maths_util
{
    vector<long long> fact;
    vector<bool> is_prime;
    maths_util(int n = 200001, long long q = R)
    {
        fact.resize(n);
        is_prime.assign(n + 1, true);

        fact[0] = 1;
        for(int i = 1; i < n; i++)
            fact[i] = (fact[i-1] * i) % q;

        is_prime[0] = is_prime[1] = false;
        for(int i = 2; i <= n; i++)
            if(is_prime[i])
                for(int j = i + i; j <= n; j += i)
                    is_prime[j] = false;
    }
    long long power_mod_q(long long x, long long n, long long q = R)
    {
        if(n == 0)
            return 1;
        if(n % 2 == 0)
            return power_mod_q((x * x) % q, n / 2, q);
        else 
            return (x * power_mod_q((x * x) % q, n / 2, q)) % q; 
    }

    long long inverse_mod_q(long long n, long long q = R)
    {
        return power_mod_q(n, q-2, q);
    }

    long long nCr_mod_q(long long n, long long r, long long q = R)
    {
        return (((fact[n] * inverse_mod_q(fact[r], q)) % q) * inverse_mod_q(fact[n-r], q)) % q;
    }

    long long power(long long x, long long n)
    {
        if(n == 0)
            return 1;
        if(n % 2 == 0)
            return power(x * x, n / 2);
        else 
            return x * power(x * x, n / 2); 
    }

    grid multiply(grid& a, grid& b)
    {
        int p = a.size(), q = b.size(), r = b[0].size();
        grid c(p, vector<long long>(r, 0));
        for(int i = 0; i < p; i++)
            for(int j = 0; j < r; j++)
                for(int k = 0; k < q; k++)
                    c[i][j] += a[i][k] * b[k][j];
        return c;
    }

    grid add(grid& a, grid& b)
    {
        int p = a.size(), q = a[0].size();
        grid c(p, vector<long long>(q));
        for(int i = 0; i < p; i++)
            for(int j = 0; j < q; j++)
                c[i][j] = a[i][j] + b[i][j];
        return c;
    }

    grid power(grid& a, long long n)
    {
        grid c(a.size(), vector<long long>(a.size(), 0));
        if(n == 0)
        {
            for(int i = 0; i < a.size(); i++)
                c[i][i] = 1;
            return c;
        }
        if(n % 2 == 0)
            return power(c = multiply(a, a), n / 2);
        else
            return multiply(a, c = power(c = multiply(a, a), n / 2));
        
    }
}u;

struct dsu
{
    vector<int> rank, parent, num;
    dsu(int n)
    {
        rank.assign(n, 0);
        parent.resize(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find_set(int i)
    {
        if(i == parent[i])
            return i;
        return parent[i] = find_set(parent[i]);
    }
    bool is_same_set(int i, int j)
    {
        if(find_set(i) == find_set(j))
            return true;
        return false;
    }
    void union_set(int i, int j)
    {
        if(!is_same_set(i, j))
        {
            int u = find_set(i), v = find_set(j);
            if(rank[u] == rank[v])
            {
                parent[v] = u;
                rank[u] += 1;
            }
            else if(rank[u] > rank[v])
                parent[v] = u;
            else 
                parent[u] = v;
        }
    }

};


struct graph
{
    int v, time, count;
    vector<pair<int, int>>* adj;
    vector<bool> visited, in_stack, ap, in_MST;
    stack<int> s;
    vector<int> color, cc, d, f, l, finish_time, indegree, sccs, topo, outdegree, pred, child;
    graph(int n)
    {
        v = n;
        adj = new vector<pair<int, int>>[n];
        visited.assign(n, false);
        in_stack.assign(n, false);
        ap.assign(n, false);
        color.assign(n, 0);
        cc.assign(n, -1);
        d.assign(n, -1);
        f.assign(n, -1);
        indegree.assign(n, 0);
        outdegree.assign(n, 0);
        pred.assign(n, -1);
        child.assign(n, 0);
        time = count = 0;
        finish_time.assign(2 * n, -1);
        l.assign(n, 0);
    }
    void add_edge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    void dfs()
    {
        color.assign(v, 0);
        cc.assign(v, -1);
        time = count = 0;
        finish_time.assign(2 * v, -1);
        visited.assign(v, false);
        pred.assign(v, -1);
        for(int i = 0; i < v; i++)
        {
            if(color[i] == 0)
            {
                dfs(i);
                count++;
            }
        }
        for(int i = 0; i < v; i++)
            finish_time[f[i]] = i;
    }
    void dfs(int i)
    {
        color[i] = 1;
        cc[i] = count;
        d[i] = time;
        time++;
        for(auto x : adj[i])
        {
            if(color[x.first] == 0)
            {
                pred[x.first] = i;
                dfs(x.first);
            }
        }
        color[i] = 2;
        f[i] = time;
        time++;
    }

    void scc()
    {
        graph g_t(v);
        for(int i = 0; i < v; i++)
            for(auto x : adj[i])
                g_t.add_edge(x.first, i, x.second);
        dfs();
        for(int i = 2 * v - 1; i >= 0; i--)
        {
            if(finish_time[i] != -1 && g_t.color[finish_time[i]] == 0)
            {
                g_t.dfs(finish_time[i]);
                g_t.count++;
            }
        }
        sccs = g_t.cc;
        count = g_t.count;
    }

    void topological_sort()
    {
        for(int i = 0; i < v; i++)
            if(adj[i].size())
                outdegree[i] = adj[i].size();
        for(int i = 0; i < v; i++)
            for(auto x : adj[i])
                indegree[x.first]++;
        vector<int> zero;
        for(int i = 0; i < v; i++)
            if(!indegree[i])
                zero.push_back(i);
        
        while(!zero.empty())
        {
            int v = zero.back();
            topo.push_back(v);
            zero.pop_back();
            for(auto x : adj[v])
            {
                indegree[x.first]--;
                if(!indegree[x.first])
                    zero.push_back(x.first);
            }
        }
    }

    void tarjan()
    {
        for(int i = 0; i < v; i++)
            if(!color[i])
                tarjan(i);
    }
    void tarjan(int i)
    {
        color[i] = 1;
        d[i] = time;
        time++;
        l[i] = d[i];
        s.push(i);
        in_stack[i] = true;
        for(auto x : adj[i])
        {
            if(!color[x.first])
            {
                tarjan(x.first);
                l[i] = min(l[i], l[x.first]);
            }
            else if(in_stack[x.first])
            {
                l[i] = min(l[i], d[x.first]);
            }
        }
        
        color[i] = 2;
        f[i] = time;
        time++;
        if(d[i] == l[i])
        {
            while(s.top() != i)
                cout << s.top() << ' ', in_stack[s.top()] = false, s.pop();
            cout << s.top() << '\n', in_stack[s.top()] = false, s.pop();
        }
    }

    // incomplete --->
    void articulate()
    {
        ap.assign(v, false);
        color.assign(v, 0);
        child.assign(v, 0);
        time = 0;
        d.assign(v, -1);
        f.assign(v, -1);
        l.assign(v, 0);
        pred.assign(v, -1);
        for(int i = 0; i < v; i++)
            if(color[i] == 0)
            {
                articulate(i);
                if(child[i] == 1 || child[i] == 0)
                    ap[i] = false;
            }
    }

    void articulate(int i)
    {
        color[i] = 1;
        d[i] = time;
        time++;
        l[i] = d[i];
        for(auto x : adj[i])
        {
            if(pred[i] != x.first && color[x.first] == 1)
                l[i] = min(l[i], d[x.first]);
            if(!color[x.first])
            {
                pred[x.first] = i;
                child[i]++;
                articulate(x.first);
                l[i] = min(l[i], l[x.first]);
            }
            if(l[x.first] >= d[i])
                ap[i] = true;
            
        } 
        f[i] = time;
        time++;
        color[i] = 2;
    }

    // incomplete --->
    void bridges()
    {
        time = 0;
        f.assign(v, -1);
        d.assign(v, -1);
        l.assign(v, 0);
        color.assign(v, 0);
        pred.assign(v, -1);
        for(int i = 0; i < v; i++)
            if(color[i] == 0)
                bridge(i);
    }

    void bridge(int i)
    {
        color[i] = 1;
        d[i] = time;
        time++;
        l[i] = d[i];
        for(auto itr = adj[i].begin(); itr != adj[i].end(); itr++)
        {
            if(pred[i] != itr -> first && color[itr -> first] == 1)
                l[i] = min(l[i], d[itr -> first]);
            if(!color[itr -> first])
            {
                pred[itr -> first] = i;
                bridge(itr -> first);
                l[i] = min(l[i], l[itr -> first]);
            }
            if(l[itr -> first] > d[i])
                itr -> second = 1;
        }
        color[i] = 2;
        f[i] = time;
        time++;
    }

    graph kruskal()
    {
        vector<pair<int, pair<int, int>>> edges;
        for(int i = 0; i < v; i++)
            for(auto x : adj[i])
                edges.push_back(make_pair(x.second, make_pair(i, x.first)));
        sort(edges.begin(), edges.end());
        dsu d(v);
        graph mst(v);
        for(auto x : edges)
        {
            if(!d.is_same_set(x.second.first, x.second.second))
            {
                mst.add_edge(x.second.first, x.second.second, x.first);
                d.union_set(x.second.first, x.second.second);
            }

        }
        return mst;
    }

    graph prims(int s)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        d.assign(v, INT32_MAX);
        pred.assign(v, -1);
        in_MST.assign(v, false);
        count = 0;
        d[s] = 0;
        pq.push({0, s});
        while(count < v)
        {
            int u = pq.top().second;
            if(!in_MST[u])
                in_MST[u] = true, count++;
            pq.pop();
            for(auto x : adj[u])
            {
                if(!in_MST[x.first] && d[x.first] > x.second)
                {
                    pq.push({x.second, x.first});
                    pred[x.first] = u;
                    d[x.first] = x.second;
                }
            }
        }
        graph mst(v);
        for(int i = 0; i < v; i++)
        {
            if(pred[i] != -1)
                mst.add_edge(i, pred[i], d[i]);
        }
        return mst;
    }

};

struct kmp
{
    vector<int> lps;
    string p, t;
    kmp(string& p, string& t)
    {
        this -> p = p;
        this -> t = t;
        //PREPROCESSING
        lps.assign(p.size(), 0);
        lps[0] = 0;
        int len = 0, i = 1, j;
        while(i < p.size())
        {
            if(p[i] == p[len])
                lps[i++] = ++len;
            else if(len)
                len = lps[len-1];
            else 
                lps[i++] = 0;
        }
        //STRING MATCHING
        i = j = 0;
        while(i < t.size())
        {
            if(p[j] == t[i])
                j++, i++;
            
            if(j == p.size())
            {
                //It's a match at index i - 1
                j = lps[j-1];
            }
            else if(i < t.size() && p[j] != t[i])
            {
                if(j)
                    j = lps[j-1];
                else 
                    i++;
            }
        }

        
    }
};

// Pending lazy --->
struct segment_tree
{
    int n;
    vector<int> a, tree;
    segment_tree(vector<int>& a)
    {
        this -> n = a.size();
        this -> a = a;
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }
    void build(int node, int l, int r)
    {
        if(l == r)
            tree[node] = a[r];
        else 
        {
            int mid = (l + r) / 2;
            build(2 * node + 1, l, mid);
            build(2 * node + 2, mid + 1, r);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void update(int node, int l, int r, int i, int x)
    {
        if(l == r)
            tree[node] = a[i] = x;
        else
        {
            int mid = (l + r) / 2;
            if(i <= mid && i >= l)
                update(2 * node + 1, l, mid, i, x);
            else
                update(2 * node + 2, mid + 1, r, i, x);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    int query(int node, int l, int r, int ql, int qr)
    {
        if(l == ql && r == qr)
            return tree[node];
        else
        {
            int mid = (l + r) / 2;
            if(qr <= mid)
                return query(2 * node + 1, l, mid, ql, qr);
            else if(ql > mid)
                return query(2 * node + 2, mid + 1, r, ql, qr);
            else 
                return query(2 * node + 1, l, mid, ql, mid) + query(2 * node + 2, mid + 1, r, mid + 1, qr);
        }
        
    }
}; 

struct trie
{
    struct node
    {
        char c;
        bool is_leaf;
        vector<node *> child;
        node(char ch)
        {
            c = ch;
            is_leaf = false;
            child.assign(L, nullptr);
        }
    };
    node * root;
    trie()
    {
        root = new node('#');
    }

    void insert(string& s)
    {
        node * temp = root;
        for(auto x : s)
        {
            if(!(temp -> child)[x])
                (temp -> child)[x] = new node(x);
            temp = (temp -> child)[x];
        }
        temp -> is_leaf = true;
    }

    bool has_child(node * temp)
    {
        for(auto x : temp -> child)
            if(x)
                return true;
        return false;
    }

    bool search(string& s)
    {
        node * temp = root;
        bool flag = true;
        for(auto x : s)
        {
            if(!(temp -> child)[x])
            {
                flag = false;
                break;
            }
            temp = (temp -> child)[x];
        }
        if(flag && temp -> is_leaf)
            return true;
        else
            return false;
    }

    void remove(string& s)
    {
        if(search(s))
            root = remove(root, 0, s);
    }
    node * remove(node * root, int pos, string& s)
    {
        if(pos <= s.length() - 1)
        {
            (root -> child)[s[pos]] = remove((root -> child)[s[pos]], pos + 1, s);
            bool flag = true;
            for(int i = 0; i < L; i++)
                if((root -> child)[i])
                    flag = false;
            if(root -> c != '#' && root -> is_leaf == false && flag)
            {
                delete(root);
                root = nullptr;
            }
        }
        else
        {
            root -> is_leaf = false;

            bool flag = true;
            for(int i = 0; i < L; i++)
                if((root -> child)[i])
                    flag = false;
            if(flag)
            {
                delete(root);
                root = nullptr;
            }
        }
        return root;
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& x : a)
        cin >> x;
    multiset<int> l;
    l.insert(a[0]);
    for(int i = 1; i < n; i++)
    {
        // cout << "rbegin()" << *(l.rbegin()) << '\n';
        if(a[i] <= *(l.begin()))
            l.insert(a[i]);
        else
        {
            auto x = l.lower_bound(a[i]);
            x--;
            // cout << "x" << *x << '\n';
            l.erase(x);
            l.insert(a[i]);
        }
        // for(auto x : l)
        //     cout << x << ' ';
        // cout << '\n';
    }
    int ans = 0;
    for(auto x : l)
        ans++;
    cout << ans << '\n';
    return 0;
}


