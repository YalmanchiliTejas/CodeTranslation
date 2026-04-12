#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int list[100][100];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            list[i][j] = 0;
    
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        list[a][b] = list[b][a] = 1;
    }
    vector<int> v(n - 1);
    for(int i=1;i<n;i++) v[i-1] = i;
    sort(v.begin(),v.end());
    int ans = 0;

    do{
        int now = 0;
        for(int i=0;i<v.size();i++){
            if(list[now][v[i]] == 0) break;
            now = v[i];
            if(i == v.size() - 1)ans++;             
        }
    }while(next_permutation(v.begin(), v.end()));

    cout << ans << endl;

    return 0;
}