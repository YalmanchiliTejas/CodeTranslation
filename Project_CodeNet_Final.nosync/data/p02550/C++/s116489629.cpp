#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, x, mod;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>x>>mod;

    vector<int> visited(mod);

    vector<int> v;
    int initial_sum = 0;
    int initial_cnt = 0;
    while(true){
        if (visited[x]) break;
        visited[x] = 1;
        initial_sum += x;
        v.push_back(initial_sum);
        initial_cnt++;
        x = (x*x)%mod;
    }

    v.insert(v.begin(), 0);

    vector<int> vc;
    int cycle_sum = 0;
    int cnt = 0;
    for (auto &e:visited) e = 0;
    while(true){
        if (visited[x]) break;
        visited[x] = 1;
        cycle_sum += x;
        vc.push_back(cycle_sum);
        x = (x*x)%mod;
        cnt++;
    }

    vc.insert(vc.begin(), 0);


//
//    for (auto e:v) cout<<e<<" ";
//    cout<<endl;
//    for (auto e:vc) cout<<e<<" ";
//    cout<<endl;

    if (n<=initial_cnt){
        cout<<v[n]<<endl;
    }
    else{
        n -= initial_cnt;
        cout<<initial_sum+(cycle_sum*(n/cnt)+ vc[n%cnt])<<endl;
    }

    return 0;
}



