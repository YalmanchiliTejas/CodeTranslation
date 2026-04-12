#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
    Tree t1(g, 0);
    int l = 0;
    for(int i = 0; i < n; i++){
        if(t1.dpt[i] > t1.dpt[l]) l = i;
    }
    Tree t2(g, l);
    int r = 0;
    for(int i = 0; i < n; i++){
        if(t2.dpt[i] > t2.dpt[r]) r = i;
    }
    bool b[100005]{0};
    int k = r;
    while(k != -1){
        b[k] = true;
        k = t2.par[k];
    }
    Tree t3(g, r);
    int s = -1;
    if(t2.dpt[r] % 2){
        for(int i = 0; i < n; i++){
            if(!b[i]){
                s = max(s, max(t2.dpt[i], t3.dpt[i]));
            }
        }
    }
    else{
        int m = -1;
        vector<int> v;
        for(int i = 0; i < n; i++){
            if(b[i] && t2.dpt[i] == t3.dpt[i]){
                m = i;
            }
            if(!b[i]){
                if(max(t2.dpt[i], t3.dpt[i]) == t2.dpt[r]) v.push_back(i);
                else s = max(s, max(t2.dpt[i], t3.dpt[i]));
            }
        }
        if(v.size()){
            bool f = true;
            for(int x : v){
                int j = x;
                while(true){
                    if(b[j]){
                        if(j != m) f = false;
                        break;
                    }
                    b[j] = true;
                    j = t2.par[j];
                }
            }
            if(!f) s = t2.dpt[r];
            else s = t2.dpt[r] - 1;
        }
    }
    for(int i = 1; i <= n; i++){
        if(i == 1 || i == 2) cout << 1;
        else if(i <= s) cout << 0;
        else cout << 1;
    }
    cout << endl;
}
