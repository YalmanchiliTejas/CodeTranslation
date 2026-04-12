#include <bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false);cin.tie(0);
#define setnow clock_t tStart=clock();
#define time (double)(clock() - tStart)/CLOCKS_PER_SEC;
#define setin(x) ifstream cin(x);
#define setout(x) ofstream cout(x);
typedef long long ll;
typedef long long int lli;
typedef pair < int, int> dbl;
const int maxInt = 1e9*2;
const lli maxLong = 1e18*2;
int v[10];
int n,m ;
int adj[100][100];
int ans = 0;

bool valid(int k){
    bool vv = true;
    for(int i = 1; i < k; i++)
        if(v[i] == v[k])
            vv = false;
    return vv;
}

void check(int k){
    //for(int i = 1; i <= n; i++)
    //        cout  << v[i] << ' ';
    //cout << endl;
    if(v[1] != 1)
            return;
    for(int i = 2; i <= n; i++)
        if(!adj[v[i - 1]][v[i]])
            return;
    ans++;
}


void backt(int k){
    for(int i = 1; i <= n; i++){
        v[k] = i;
        if(valid(k)){
                if(k == n)
                        check(k);
                backt(k+1);
        }
    }
}

int main(){
        cin >> n >> m;
        for(int i = 0; i < m; i++){
                int a, b;
                cin >> a >> b;
                adj[a][b] = 1;
                adj[b][a] = 1;
        }
        backt(1);
        cout << ans;
}
