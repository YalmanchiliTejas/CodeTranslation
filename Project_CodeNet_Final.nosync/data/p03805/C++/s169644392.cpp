#include<bits/stdc++.h>
using namespace std;

using ll=long long;

const int MAX = 2200000;
const long long MOD = 1000000007;
long long INF = 90000000001000;


int main() {

    int n,m;cin >> n >> m;
    int e[10][10];
    for (int i = 0; i < 10; ++i)
    {
       for (int j = 0; j < 10; ++j)
       {
           e[i][j] = 0;
       }
    }
    for (int i = 0; i < m; ++i)
    {
        int a,b;cin >> a >> b;a--;b--;
        e[a][b] = e[b][a] = 1;
    }

    vector<int> p(n-1);
    for (int i = 0; i < n-1; ++i)
    {
       p[i] = i+1;
    }
    int cnt=0;
    do{
        
        int flag = 1;
        for (int i = 0; i < n-2; ++i)
        {
            if(i==0&&e[p[0]][0]!=1){flag = 0; break;}
            if(e[p[i+1]][p[i]]!=1){flag = 0; break;}
        }
        if(flag) cnt++;
    }while(next_permutation(p.begin(),p.end()));

    cout << cnt;

return 0;
}


