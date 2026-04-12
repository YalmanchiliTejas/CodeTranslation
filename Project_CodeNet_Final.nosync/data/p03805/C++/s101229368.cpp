#include<bits/stdc++.h>
using namespace std;
typedef long long ll;





int main(){
    
 
    int n, m;      cin >> n >> m;
    vector<bool> seen(n);
    vector<vector<bool>> g(n, vector<bool>(n));
    for(int i=0; i<m; i++){
        int a, b;   cin >> a >> b;
        a--;    b--;
        g.at(a).at(b) = g.at(b).at(a) = true;
    }
    vector<int> route(n);
    for(int i=0; i<n; i++)  route.at(i)=i;

    int cnt=0;

    do{
        if(route[0]!=0) break;
        bool flag=true;
        for(int i=0; i<n-1; i++){
            int from = route.at(i);
            int to = route.at(i+1);
            if(!g[from][to]) flag = false;
        }
        if(flag) cnt += 1;

    }while(next_permutation(route.begin(), route.end()));

    cout << cnt << endl;
}