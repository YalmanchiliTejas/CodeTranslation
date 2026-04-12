#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;

struct Graph
{
    int n;
    vector<vector<int>> g;
    
    Graph(int n) : n(n){
        g.resize(n);
    }
    
    void init(int n_){
        n = n_;
        g.resize(n_);
    }
    
    void add_edge(int from, int to){
        g[from].push_back(to);
    }
};

struct Tree	//create tree(directed) from graph(undirected)
{
    int n;
    int root;
    vector<vector<int>> t;
    vector<int> par;
    vector<int> dpt;
    
    void init(Graph &g, int root_){
        n = g.n;
        root = root_;
        t.resize(n);
        par.resize(n);
        dpt.resize(n);
        fill(dpt.begin(), dpt.end(), -1);
        queue<int> que;
        par[root] = -1;
        dpt[root] = 0;
        que.push(root);
        while(que.size()){
            int pa = que.front();
            que.pop();
            for(int ch : g.g[pa]){
                if(dpt[ch] == -1){
                    t[pa].push_back(ch);
                    par[ch] = pa;
                    dpt[ch] = dpt[pa] + 1;
                    que.push(ch);
                }
            }
        }
    }

    Tree(){}
    
    Tree(Graph &g, int root_){
        init(g, root_);
    }
};

int main()
{
    int n;
    cin >> n;
    Graph g(n);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g.add_edge(a, b);
        g.add_edge(b, a);
    }
    if(n == 2){
        cout << "Second" << endl;
        return 0;
    }
    Tree t(g, 0);
    P p[100002];
    for(int i = 0; i < n; i++) p[i] = P(t.dpt[i], i);
    sort(p, p + n, greater<P>());
    bool del[100002]{0};
    for(int i = 0; i < n; i++){
        int u = p[i].second;
        int k = 0;
        for(int v : t.t[u]){
            if(!del[v]) k++;
            del[v] = true;
        }
        if(k >= 2){
            cout << "First" << endl;
            return 0;
        }
        if(k == 1){
            del[u] = true;
        }
        if(k == 0 && u == 0){
            cout << "First" << endl;
            return 0;
        }
    }
    cout << "Second" << endl;
}