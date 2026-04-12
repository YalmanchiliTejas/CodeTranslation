#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5 ;
int p[N],n ;
int rnk[N];
vector < pair < int , pair < int , int > > > v;
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
    scanf("%d",&n);
    vector < pair < int ,int > > v1, v2;
    for(int i = 1 ; i <= n ; i++){
        int x,  y;
        scanf("%d%d",&x,&y);
        v1.push_back({x,i});
        v2.push_back({y,i});
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for(int i = 1 ; i < n ; i++){
        v.push_back({v1[i].first - v1[i - 1].first,{v1[i].second,v1[i - 1].second}});
        v.push_back({v2[i].first - v2[i - 1].first,{v2[i].second,v2[i - 1].second}});
    }
    sort(v.begin(),v.end());
    long long ans = 0 ;
    for(int i = 0 ; i < v.size() ; i++){
        int x = v[i].second.first;
        int y = v[i].second.second;
        long long cost = v[i].first;
        if (isConnected(x, y))
            continue;
        connect(x,y);
        ans += cost;
    }
    cout << ans;
    return 0;
}
