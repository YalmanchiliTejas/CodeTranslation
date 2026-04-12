#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
#define INF 1e+10
#define MAX_V 10
 
 
// <最短距離, 頂点の番号>
using P = pair<int, int>;

 
 
signed main(){
    int n;
    cin >> n;
    vector<pair<int, int>> x(n),y(n);
    int x0,y0;
    for(int i=0;i<n;i++){
        cin >> x0 >>y0;
        x[i]=make_pair(x0,i);y[i]=make_pair(y0,i);
    }
    //P r[4][n];
    sort(x.begin(),x.end());sort(y.begin(),y.end());
  
    vector<vector<pair<int,int>>> r(4,vector<pair<int,int>>(n));
   
    for(int i =0;i<n-1;i++){
        r[0][x[i].second]=make_pair(x[i+1].first - x[i].first,x[i+1].second);
        r[1][x[i+1].second]=make_pair(x[i+1].first - x[i].first,x[i].second);
          r[2][y[i].second]=make_pair(y[i+1].first - y[i].first,y[i+1].second);
        r[3][y[i+1].second]=make_pair(y[i+1].first - y[i].first,y[i].second);
    }
    r[0][x[n-1].second]=make_pair(-1,-1);
     r[1][x[0].second]=make_pair(-1,-1);
      r[2][y[n-1].second]=make_pair(-1,-1);
       r[3][y[0].second]=make_pair(-1,-1);

    
    int d[n];
    fill(d,d+n,INF);
    int q[n]={};
    d[0]=0;
   int p=0;
   int ans=0;
   P o=make_pair(0,0);
   priority_queue<P, vector<P>, greater<P> > que;
   //cout << r[0][0].first<<endl;

   for(int i=0;i<n-1;i++){
       q[p]=1;
      
       for(int t=0;t<4;t++){
           if(r[t][p].first!=-1){
           if(r[t][p].first<d[r[t][p].second]){
               d[r[t][p].second]=r[t][p].first;
           }
           que.push(r[t][p]);
           }

       }
        //cout << que.top().first<< endl;
         //cout << que.top().second << endl;
        //cout <<q[ que.top().second ]<<' ';
       while(q[o.second]==1){
           o = que.top();
           que.pop();
            // cout <<q[ o.second ]<< endl;
       }
       ans+= o.first;
      // cout << ans << endl;
       p=o.second;
     //cout << p << endl;

       

   }
   cout << ans;
    return 0;
}