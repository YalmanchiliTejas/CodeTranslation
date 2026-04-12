#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define MAX_N (1<<19)
#define INF 100000000
#define MOD 1000000007
#define RANK 1000000000
#define EPS 1e-10
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> IP;

struct segtree{
    int n, dat[2*MAX_N-1]; //(1<<17) = 130000
    int add[2*MAX_N-1];

    void init(int n_){
        n = 1;
        while(n < n_) n *= 2;
        for(int i = 0; i < 2*n-1; i++) dat[i] = 0;
        for(int i = 0; i < 2*n-1; i++) add[i] = 0;
    }

    void Add(int a, int b, int k, int l, int r, int v){
        if(a >= r || b <= l) return;
        if(a <= l && r <= b){
            add[k] += v;
            return;
        }
        Add(a,b,k*2+1,l,(r+l)/2,v);
        Add(a,b,k*2+2,(r+l)/2,r,v);
        dat[k] = min(dat[k*2+1]+add[k*2+1],dat[k*2+2]+add[k*2+2]);
    }

    //(a,b,0,0,seg.n)??§?????¶
    int query(int a, int b, int k, int l, int r, int v){
        if(k >= n-1) return k-(n-1);
        v += add[k];
        if(dat[k*2+2]+v < 0) return query(a,b,k*2+2,(l+r)/2,r,v);
        else return query(a,b,k*2+1,l,(l+r)/2,v);
    }
} seg;

int n, q;
string s;
priority_queue<int, vector<int>, greater<int> > que;
int bla[300000];

int main(){
    cin >> n >> q;
    seg.init(n);
    cin >> s;
    rep(i,n){
        if(s[i] == ')'){
            que.push(i);
            bla[i]++;
        }
    }
    int cnt = 0;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == ')') cnt++;
        else cnt--;
        seg.Add(i,i+1,0,0,seg.n,cnt);
    }
    rep(i,q){
        int x; cin >> x;
        x--;
        if(s[x] == '('){
            s[x] = ')';
            seg.Add(0,x+1,0,0,seg.n,2);
            que.push(x);
            bla[x]++;
            while(true){
                int p = que.top();
                que.pop();
                if(bla[p] > 0){
                    s[p] = '(';
                    seg.Add(0,p+1,0,0,seg.n,-2);
                    bla[p]--;
                    cout << p+1 << endl;
                    break;
                }
            }
        } else{
            s[x] = '(';
            bla[x]--;
            seg.Add(0,x+1,0,0,seg.n,-2);
            int y = seg.query(0,n,0,0,seg.n,0);
            s[y] = ')';
            bla[y]++;
            que.push(y);
            seg.Add(0,y+1,0,0,seg.n,2);
            cout << y+1 << endl;
        }
    }
}