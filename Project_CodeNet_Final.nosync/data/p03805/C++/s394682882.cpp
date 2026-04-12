#include <bits/stdc++.h>
using namespace std;

void pass(int l, int x, int n);

int ans;
bool toru[8];
vector<int> road[8];
signed main()
{
    int n, m, a, b;

    cin >> n >> m;
    for(int i=0 ;i<m ;i++ ){
        cin >> a >> b;

        road[a-1].push_back(b-1);
        road[b-1].push_back(a-1);
    }
    pass(0, 0, n);

    cout << ans << endl;
    return (0);
}

void pass(int l, int x, int n)
{   
    toru[x] = true;
    if(l == n-1){
        ans++;
    }
    else{
        for(int i=0 ;i<road[x].size() ;i++ ){
            if(toru[road[x][i]] == false){

                pass(l+1, road[x][i], n);
                toru[road[x][i]] = false;
            }
        }
    }

    return;
}