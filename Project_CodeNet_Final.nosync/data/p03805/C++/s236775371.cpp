#include <bits/stdc++.h>
#define INF 1e18
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define MAX 1000
#define ll long long
#define P pair<int,int>
using namespace std;
const int mod = 1000000007;
//char c[MAX][MAX];
int step[MAX][MAX];
int H,W,N; 
int vy[4] ={1,-1,0,0}, vx[4] = {0,0,-1,1}; //up,down,left,right 

signed main(){
    int n,m; cin >> n >> m;
    int a[50],b[50];
    rep(i,m) cin >> a[i] >> b[i];
    vector<int> v;
    for(int i=1;i < n+1;i++) v.push_back(i);
    int ans=0;
    do{
        int cnt = 0;
        //rep(i,n) cout << v[i] << " ";
        //cout << endl;
        int cnt1 = 0;
        for(int i=0;i<n-1;i++){
            for(int k=0;k<m;k++){ 
                if(v[i] == a[k] && v[i+1] == b[k]){
                    cnt1=1;
                } else if(v[i] == b[k] && v[i+1] == a[k]){
                    cnt1=1;
                } 
            }
            if(cnt1) cnt++;
            cnt1 = 0;
        }
        if(cnt == n-1) ans++;
    } while(next_permutation(v.begin()+1,v.end()));

    cout << ans << endl;
    return 0;
}