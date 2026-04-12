#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>

using namespace std;

#define INF 1 << 29
#define LL long long int

#define FOR(i,a,b) for(int i=(a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)

struct unionfind{

  unionfind(int n) : par(n) , size(n,1){
    REP(i,n) par[i] = i;
  }

  int root(int x){
    if(par[x] == x) return x;
    return (par[x] = root(par[x]));
  }

  bool find(int x,int y){
    return root(x) == root(y);
  }

  void set(int x,int y){
    x = root(x);
    y = root(y);

    if(x == y)return;

    if(size[x] > size[y]){
      par[y] = par[x];
      size[x] += size[y];
    }else{
      par[x] = par[y];
      size[y] += size[x];
    }

    return;
  }

private:
  vector<int> par;
  vector<int> size;

}typedef UF;

LL const MOD = 1000000007;

struct edge{
    LL s,t;
    LL cost;
    edge(LL v1,LL v2,LL y):s(v1),t(v2),cost(y){

    }

    bool operator <(const edge& right)const{
        return cost < right.cost;
    }
};

struct forX{
    LL id;
    LL x;
    LL y;

    forX(){

    }

    forX(LL ind,LL i,LL j):id(ind),x(i),y(j){

    }

    bool operator <(const forX& right)const{
        return x < right.x;
    }
};

struct forY{
    LL id;
    LL x;
    LL y;

    forY(){

    }

    forY(LL ind,LL i,LL j):id(ind),x(i),y(j){

    }

    bool operator <(const forY& right)const{
        return y < right.y;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    LL n;
    cin >> n;

    vector<forX> vecx(n+1);
    vector<forY> vecy(n+1);

    for(int i = 1; i < n+1; i++){
        LL x,y;
        cin >> x >> y;
        vecx[i] = forX(i,x,y);
        vecy[i] = forY(i,x,y);
    }
    sort(vecx.begin()+1,vecx.end());
    sort(vecy.begin()+1,vecy.end());

    vector<edge> e;
    for(int i = 1; i < n; i++){
        e.push_back(edge(vecx[i].id,vecx[i+1].id,min(abs(vecx[i+1].x-vecx[i].x),abs(vecx[i+1].y - vecx[i].y))));
        e.push_back(edge(vecy[i].id,vecy[i+1].id,min(abs(vecy[i+1].y-vecy[i].y),abs(vecy[i+1].x - vecy[i].x))));
    }

    UF uf = unionfind(n+1);

    sort(e.begin(),e.end());

    LL ans = 0;

    for(int i = 0; i < e.size(); i++){
        if(uf.find(e[i].s,e[i].t)){

        }else{
            ans += e[i].cost;
            uf.set(e[i].s,e[i].t);
        }
    }

    cout << ans << endl;

    
    return 0;
}