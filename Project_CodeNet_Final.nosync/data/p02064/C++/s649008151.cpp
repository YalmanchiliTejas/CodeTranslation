#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;

int main(){
    int N,S,T;
    cin >> N >> S >> T;
    vector<int> ok(N+1,0);
    vector<vector<int>> dist(N+1,vector<int>(N+1,0));
    vector<P> v;
    for(int i=1;i<=N;i++){
        if(i==S) continue;
        cout << "? " << S << " " << i << endl;
        int res;
        cin >> res;
        dist[S][i] = res;
        dist[i][S] = res;
    }
    for(int i=1;i<=N;i++){
        if(i==T || i==S) continue;
        cout << "? " << i << " " << T << endl;
        int res;
        cin >> res;
        dist[i][T] = res;
        dist[T][i] = res;
    }
    vector<int> ans;
    for(int i=1;i<=N;i++){
        if(dist[S][i]+dist[i][T]==dist[S][T]) v.push_back({dist[S][i],i});
    }
    sort(v.begin(),v.end());
    ans.push_back(v[0].second);
    int now = v[0].second;
    int id = 0;
    while(now!=T){
        for(int i=id+1;i<v.size();i++){
            cout << "? " << now << " " << v[i].second << endl;
            int res;
            cin >> res;
            if(dist[S][now]+res==dist[S][v[i].second]){
                ans.push_back(v[i].second);
                now = v[i].second;
                id = i;
                break;
            }
        }
    }
    cout << "! ";
    int n = ans.size();
    for(int i=0;i<n;i++) cout << ans[i] << (i!=n-1? " ":"\n");
}
