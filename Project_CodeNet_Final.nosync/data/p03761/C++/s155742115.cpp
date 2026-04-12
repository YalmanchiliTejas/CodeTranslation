#include<bits/stdc++.h>
using namespace std;

#define lli long long
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(),i.rend()
#define rep0(i,j) for(int i=0;i<j;i++)
#define rep1(i,j) for(int i=1;i<=j;i++)
#define rep0d(i,j) for(int i=j-1;i>=0;i--)
#define MOD 1000000007
#define MAX (lli)1e12 
typedef pair<lli, lli> p; 
class Graph{
  lli V;
  vector<list<p>> adj; 
  const lli INF = (lli)1e12;

  public: 
  Graph(lli V): adj(V){ 
    this->V = V; 
  } 

  void addEdge(lli u, lli v, lli w){ 
    adj[u].push_back(make_pair(v, w)); 
  } 

  lli edgeNum(){
    lli sum=0;
    rep0(i,V)sum+=adj[i].size();
    return sum;
  }

  vector<lli> dfs(lli from){//vec[i]==j: j->iっていうもとに戻れる道がある
    vector<lli> vec(V, -1);
    vec[from]=0;
    dfs_sub(0,from,vec);
    return vec;
  }
  
  void dfs_sub(lli distance, lli from, vector<lli>& vec){
    for(auto e: adj[from]){
      if(vec[e.first] != -1)continue;
      vec[e.first] = distance + e.second;
      dfs_sub(vec[e.first], e.first, vec);
    }
  }

  vector<lli> bfs(lli n){
    queue<lli> q;
    vector<lli> vec(V,-1);

    q.push(n);
    vec[n]=0;
    while(!q.empty()){
      lli p=q.front();
      q.pop();
      for(auto e:adj[p]){
        if(vec[e.first]==-1){
          q.push(e.first);
          vec[e.first] = e.second + vec[p];
        }
      }
    }
    return vec;
  }

  vector<lli> shortestPath(lli src){ 
    priority_queue< p, vector <p> , greater<p> > pq; 
  
    vector<lli> dist(V, INF); 
    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
  
    while (!pq.empty()) { 
        lli u = pq.top().second; 
        pq.pop(); 
  
        list<p>::iterator i; 
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) { 
            lli v = i->first; 
            lli weight = i->second; 
  
            if (dist[v] > dist[u] + weight) { 
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 
    for(lli i=0;i<V;i++)if(dist[i]==INF)dist[i]=-1;
    return dist;
  } 

};

struct UF{
    vector<lli> par,size;

    UF(lli N) : par(N), size(N, 1){
        rep0(i,N)par[i] = i;
    }

    lli root(lli x){
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(lli x, lli y){
        lli rx = root(x);
        lli ry = root(y);
        if(rx == ry) return;
        par[rx] = ry;
        size[rx] += size[ry];
    }

    bool same(lli x, lli y){
        lli rx = root(x);
        lli ry = root(y);
        return rx == ry;
    }

    lli getSize(lli x){
        return size[x];
    }
};
struct BIT{
  vector<lli> tab;//bit table
  BIT(int n):tab(n+1){
    rep0(i,n+1)tab[i]=0;
  }

  void add(int p, lli num){
    for(++p;p<tab.size();p+=p&-p)tab[p]+=num;
  }

  lli sum(int p){//from 0 to p
    lli ans=0;
    for(++p;p>0;p-=p&-p)ans+=tab[p];
    return ans;
  }

  void debug(){
    rep0(i,tab.size())cout << tab[i] << ' ';
    cout << endl;
  }
};

//pairに関するもの
lli sum(p c){
  return (c.first + c.second);
}
p operator-(const p & l,const p & r) {   
    return {l.first-r.first,l.second-r.second};                                    
}
bool cmpf(const pair<lli, lli> left, const pair<lli, lli> right) {
    return left.first < right.first;
}
bool cmps(const pair<lli, lli> left, const pair<lli, lli> right) {
    return left.second < right.second;
}
 
lli gcd(lli a, lli b){
    if(a < b)return gcd(b, a);
    lli temp;
    while((temp = a%b)){
        a=b;
        b=temp;
    }
    return b;
}
lli lcm(lli a, lli b){
    return a*b/gcd(a,b);
}

struct nCr{
  vector<lli> f, rf;
  lli count=0;
  nCr(lli num): f(num), rf(num){
      count = num;
      f[0] = 1;
      rep1(i, num) f[i] = (f[i - 1] * i) % MOD;
      rep0(i, num+1) rf[i] = inv(f[i]);
  }
    
  lli inv(lli x) {
      lli res = 1;
      lli k = MOD - 2;
      lli y = x;
      while (k) {
          if (k & 1) res = (res * y) % MOD;
          y = (y * y) % MOD;
          k /= 2;
      }
      return res;
  }
  lli C(lli n, lli k) {
      if(k > n || k<0)return 0;
      lli a = f[n];
      lli b = rf[n-k];
      lli c = rf[k];
   
      lli bc = (b * c) % MOD;
      return (a * bc) % MOD;
  }
};

int main(){
  lli n;
  cin >> n;
  string str;
  vector<lli>vec(26,MAX);
  rep0(i,n){
    cin >> str;
    vector<lli>temp(26,0);
    for(auto e:str)temp[e-'a']++;
    rep0(i,26)vec[i]=min(temp[i],vec[i]);
  }
  
  rep0(i,26){
    rep0(j,vec[i])cout << (char)('a'+i);
  }
}