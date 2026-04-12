
#include <bits/stdc++.h>

#define fast()           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(dat)         dat.begin(), dat.end()
#define loop(i, to)      for (int i = 0; i < to; i++)
#define count(i, to)     for (int i = 1; i <= to; i++)
#define foreach(dat, i)  for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); i++)

typedef long long        num;

using namespace std;

int n, pr[100005], ans;

pair<int, int> x[100005], y[100005];

struct triple {
    
    int d, a, b;
    
    triple(int i, int j, int k) {
        
        d = k;
        
        a = i;
        
        b = j;
        
    }
    
};

vector<triple> edge;

int root(int a) {
    
    if (pr[a] == a)  return a;
        
    return pr[a] = root(pr[a]);
    
}

void combine(int a, int b) {
    
    int pa = root(a), pb = root(b);
    
    pr[pb] = pa;
    
}

bool cmp(triple a, triple b) {
    
    return a.d < b.d;
    
}

int main() {
    
    cin >> n;
    
    loop (i, n) {
        
        int a, b;
        
        cin >> a >> b;
        
        x[i] = {a, i};
        
        y[i] = {b, i};
        
        pr[i] = i;
        
    }
    
    sort(x, x + n);
    
    sort(y, y + n);
    
    loop (i, n - 1) {
        
        edge.push_back(triple(x[i].second, x[i + 1].second, abs(x[i].first - x[i + 1].first)));
        
        edge.push_back(triple(y[i].second, y[i + 1].second, abs(y[i].first - y[i + 1].first)));
        
    }
    
    sort(all(edge), cmp);
    
    loop (i, edge.size()) {
        
        triple tmp = edge[i];
        
        int pa = root(tmp.a), pb = root(tmp.b);
        
        if (pa != pb) {
            
            ans += tmp.d;
            
            combine(tmp.a, tmp.b);
            
        }
        
    }
    
    cout << ans << endl;
    
}
