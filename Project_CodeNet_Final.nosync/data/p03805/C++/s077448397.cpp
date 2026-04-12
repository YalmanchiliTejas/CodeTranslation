#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for(int (i) = (a);(i) < (b);i++)
#define Rep(i,n) For((i),0,(n))
#define All(a) (a).begin(),(a).end()
#define sp " "
#define INF 1e9
#define F first
#define S second


const int MAX = 402;

typedef long long ll;
const ll MOD = 1000000007;
const ll MOD_9 = 998244353;


int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> G(n,vector<int>(n,0));
    Rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a][b] = 1;
      	G[b][a] = 1;
    }
    vector<int> vec(n-1);
    Rep(i,n-1)vec[i] = i+1;
    int v = 0;
    int ans = 0;
    do{
      	v = 0;
        Rep(i,n-1){
            int next = vec[i];
            if(G[v][next] == 1){
                v = next;
            }else break;
            if(i == n-2)ans++;
        }
    }while(next_permutation(vec.begin(),vec.end()));
    cout << ans << endl;
}