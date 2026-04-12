#include <bits/stdc++.h>
#define ll long long
using namespace std;
int const N = 1e5+9;
int p[N];
int rnk[N];
int parent(int x){
    if(p[x] == x)
        return x;
    return p[x] = parent(p[x]);
}
bool isConnected(int x , int y){
    return parent(x) == parent(y);
}
void connect(int x , int y){
    if(isConnected(x,y))
        return;
    int pOfx = parent(x);
    int pOfy = parent(y);
    if(rnk[pOfx] > rnk[pOfy]){
        p[pOfy] = pOfx;
    }else if(rnk[pOfy] > rnk[pOfx]){
        p[pOfx] = pOfy;
    }else{
        p[pOfy] = pOfx;
        rnk[pOfx]++;
    }
}
void preDSU(){
    for(int i = 0;i<N;i++){
        p[i] = i;
    }
}

int main(){
    preDSU();
    int n;
    cin>>n;
    map<pair<int,int> , int> indx;
    set<pair<int,int>> x , y;
    for(int i = 0;i<n;i++){
        int xx , yy;
        cin>>xx>>yy;
        indx[{xx,yy}]++;
        x.insert({xx,yy});
        y.insert({yy,xx});
    }
    int k = 0;
    for(auto &i : indx){
        i.second = k++;
    }
    vector<pair<int,pair<int,int>>>mst;
    pair<int,int> last = {-1,-1};
    for(auto i : x){
        if(last.first != -1){
            mst.push_back({i.first-last.first , {indx[i] , indx[last]} });
        }
        last = i;
    }
    last = {-1,-1};
    for(auto i : y){
        if(last.first != -1){
            mst.push_back({i.first-last.first , {indx[{i.second , i.first}] , indx[{last.second , last.first}]} });
        }
        last = i;
    }
    sort(mst.rbegin(),mst.rend());
    ll ans = 0;
    while(!mst.empty()){
        int cost = abs(mst.back().first);
        int x = mst.back().second.first;
        int y = mst.back().second.second;
        mst.pop_back();
        if(!isConnected(x,y)){
            ans+=cost;
            connect(x,y);
        }
    }
    cout<<ans;
    return 0;
}