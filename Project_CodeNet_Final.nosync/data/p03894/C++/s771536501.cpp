#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define int long long
#define vec(a,n) vector<int> (a)((n))
#define Vec(a,n) vector<string> (a)((n))
#define twovec(a,n,m) vector<vector<int>> a(n,vector<int>(m,0))
#define Twovec(a,n,m) vector<vector<double>> a(n,vector<double>(m,0))
#define P pair<int,int>
#define All(a) (a).begin(),(a).end()
#define Sort(a) sort(All(a))
#define Reverse(a) reverse(All(a))
#define PQ(n) priority_queue<P,vector<P>,greater<P>> (n)
#define pq(n) priority_queue<int> (n)
#define print(a) cout << (a) << endl;
using namespace std;
int max_int = 1000000007;
void Debug(auto a);
int nibul(auto a,auto b);
int nibuu(auto a,auto b);
void input(vector<int>& a,int n);
class Modulo{
public:
    int val;
    static const int mod = 1e9+7;
    vector<int> factable = {1};
    vector<int> invtable = {1};
    int pro(int x,int y){return ((x%mod)*(y%mod))%mod;}
    int sum(int x,int y){return ((x%mod)+(y%mod))%mod;}
    int dif(int x,int y){int d =((x%mod)-(y%mod))%mod;if(d>=0){return d;}else{return d+mod;}}
    int quo(int x, int y){return pro(x,pow(y,mod-2));}
    int pow(int x,int y){
        if(y<=0){return 1;}
        if(y%2==0){int d = pow(x,y/2);return ((d%mod)*(d%mod))%mod;}
        else{return (x*pow(x,y-1))%mod;}
    }
    void operator=(int n){this->val = n%mod;}
    int operator+(int n){return sum(this->val,n);}
    int operator-(int n){return dif(this->val,n);}
    int operator*(int n){return pro(this->val,n);}
    int operator/(int n){return quo(this->val,n);}
    void operator+=(int n){this->val = sum(this->val,n);}
    void operator-=(int n){this->val = dif(this->val,n);}
    void operator*=(int n){this->val = pro(this->val,n);}
    void operator/=(int n){this->val = quo(this->val,n);}
    int fac(int x){
        //x! mod mod
        if(factable.size()<=x){
            int s = factable.size();
            FOR(i,s,x+1){
                factable.push_back(pro(i,factable.back()));
                invtable.push_back(quo(1,factable.back()));
            }
        }
        if(x<0) return 1;
        else return factable[x];
    }
    int facinv(int x){
        if(invtable.size()<=x){
            int s = invtable.size();
            FOR(i,s,x+1){
                factable.push_back(pro(i,factable.back()));
                invtable.push_back(quo(1,factable.back()));
            }
        }
        if(x<0) return 1;
        else return invtable[x];
    }
    int com(int x,int y){
        //xCy mod mod = x!/((x-y)!*y!) mod mod
        if(x-y<y)return com(x,x-y);
        return pro(fac(x),pro(facinv(x-y),facinv(y)));
    }
};
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};


int n,m;

signed main(){
    int q;
    m = 1;
    cin >> n >> q;
    vec(a,n+2);
    a[1] = 2;
    a[2] = 1;
    REP(i,q){
        int s,t;
        cin >> s >> t;
        if(a[s-1] == 2 || a[s+1] == 2){
            a[s] = 1;
        }
        if(a[t-1] == 2 || a[t+1] == 2){
            a[t] = 1;
        }
        swap(a[s],a[t]);
        if(a[s] == 2 || a[t] == 2){
            a[s-1] = max(m,a[s-1]);
            a[s+1] = max(m,a[s+1]);
            a[t-1] = max(m,a[t-1]);
            a[t+1] = max(m,a[t+1]);
        }
    }
    int ans = 0;
    REP(i,n){
        if(a[i+1] == 1){
            ans++;
        }
        if(a[i+1] == 2){
            if(a[i] == 0 && i != 0){
                ans++;
            }
            if(a[i+2] == 0 && i+2 != n+1){
                a[i+2]++;
            }
            ans++;
        }
    }
    print(ans);

    return 0;
}

void Debug(auto a){
    cout << "{ ";
    for(auto b: a){
        cout << b << " ";
    }
    cout << "}" << endl;
}
int nibul(auto a,auto b){
    int x = lower_bound(All(a),b) - a.begin();
    //key以上の初めてのitr
    return x;
}
int nibuu(auto a,auto b){
    int x = upper_bound(All(a),b) - a.begin();
    //key以下の最後のitr
    return x-1;
}

void input(vector<int>& a,int n){
    REP(i,n){
        cin >> a[i];
    }
}
