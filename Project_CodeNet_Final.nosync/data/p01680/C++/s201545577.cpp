#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;
const lli mod = 1e9+7;

struct UnionFindTree{
    vector<int> v;
    vector<int> rank;
    int numgroup;
     
    UnionFindTree(int n): v(n, -1), rank(n, 0), numgroup(n){}
    int Find(int x){
        if(v[x] < 0) return x;
        return v[x] = Find(v[x]);
    }
    void Union(int a, int b){
        a = Find(a);
        b = Find(b);
        if(a == b) return;
        if(rank[a] < rank[b]) swap(a, b);
        if(rank[a] == rank[b]) rank[a]++;
        v[b] = a;
        numgroup--;
    }
};

lli modpow(lli n, lli p, lli mod){
    lli res = 1;
    for(int i=63; i>=0; i--){
        res = res*res %mod;
        if((p & 1LL<<i) != 0) res = res*n %mod;
    }
    return res;
}

int main(){
    while(1){
        int n,m;
        cin >> n >> m;
        if(n==0) break;
        
        UnionFindTree uft(n);
        for(int i=0; i<m; i++){
            int a,b;
            cin >> a >> b;
            a--; b--;
            uft.Union(a, b);
        }
        if(m == 0){
            cout << modpow(2, n, mod) << endl;
        }else{
            cout << (modpow(2, uft.numgroup, mod) +1)%mod << endl;
        }
    }
    return 0;
}

