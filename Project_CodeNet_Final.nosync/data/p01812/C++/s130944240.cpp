#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;


int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int>d(m);
    map<int,int>mp;
    int v[101][101]={};
    for(int i=0;i<m;i++){
        cin >> d[i];
        d[i]--;
        mp[d[i]] = i;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin >> v[i][j];
            v[i][j]--;
        }
    }
    int bits = (1<<m)-1;
    vector<bool> flag((1<<m)+1);
    vector<int> dst((1<<m)+1);
    queue<int>q;
    q.push(bits);
    flag[bits]= 1;
    dst[bits]= 0;
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        for(int i=0;i<k;i++){
            int sa = 0;
            for(int j=0;j<m;j++){
                if(x&(1<<j)){
                    if(mp.find(v[d[j]][i])!=mp.end()){
                        int y = mp[v[d[j]][i]];
                        if(!(sa&1<<y))sa += 1<<y;
                    }
                }
            }
            if(!flag[sa]){
                flag[sa]=1;
                dst[sa] = dst[x]+1;
                q.push(sa);
            }
        }
    }
    cout << dst[0] << endl;
    return 0;
}
