#include<bits/stdc++.h>
#define dbug printf("I am here\n");
#define Fast ios_base::sync_with_stdio(false); cin.tie(0);
#define vs            v.size()
#define ss            s.size()
#define sot(v)        sort(v.begin(),v.end())
#define rev(v)        reverse(v.begin(),v.end())
#define ii            pair<int, int>
#define int           long long
#define ull           unsigned long long
#define pb            push_back
#define mpp           make_pair
#define Okay          0
#define pi            3.14159

const int inf = 1e6;
const int cont = 1e18;
using namespace std;

bool graph[10][10];

void solve(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        a--, b--;
        graph[a][b] = graph[b][a] = true;
    }

    vector<int>order(n);
    for(int i=0; i<n; i++)order[i] = i;
    int ans = 0;

    do{
        if(order[0] != 0)break;
        bool ok = true;
        for(int i=0; i<n-1; i++){
            int from = order[i];
            int to = order[i+1];
            if(graph[from][to] == 0)ok = false;
        }
        if(ok)ans++;
    }while(next_permutation(order.begin(), order.end()));

    cout<<ans<<endl;

}

int32_t main() {
   Fast;
   int tst;

    solve();
    return Okay;
}

