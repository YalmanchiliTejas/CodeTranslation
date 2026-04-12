#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <map>
#include <cstring>
#include <iomanip>
#include <queue>
using namespace std;
vector<pair<int, int> > edge[100000];
int MOD = 1000000007;
void calc(vector<long long>& dis, vector<long long>& pat, int S, int T){
   priority_queue<pair<long long,int> > pq;
   pat[S]=1;
   dis[S]=0;
   pq.push(make_pair(0,S));
   while(!pq.empty()){
      pair<long long,int> p = pq.top();
      pq.pop();
      long long dist = -p.first;
      int node = p.second;
      ////cout << node <<" " <<  dis[node]  <<"="<< dist  << " " << pat[node] << endl;
      if( dist > dis[node] ) continue;
      if( node == T ) break;
      for(int ei = 0; ei < (int)edge[node].size(); ei++){
         int nextnode= edge[node][ei].first;
         int elen = edge[node][ei].second;
         long long nextdist = dist+elen;
         ////cout << nextdist << " " << nextnode << " " << dis[nextnode] << endl;
         if( nextdist > dis[nextnode] ) continue;
         else if( nextdist < dis[nextnode] ){
            dis[nextnode] = nextdist;
            pat[nextnode] = pat[node];
            ////cout << nextdist << " " << nextnode<< endl;
            pq.push(make_pair(-nextdist, nextnode));
         }
         else{
            pat[nextnode] += pat[node];
            pat[nextnode] %= MOD;
         }
      }
   }
}
int main(){
   int N, M;
   cin >> N >> M;
   int S,T;
   cin >> S >> T;
   S--;
   T--;
   for( int i = 0 ; i < M; i++){
      int U,V,D;
      cin >> U >> V >> D;
      U--;
      V--;
      edge[U].push_back(make_pair(V,D));
      edge[V].push_back(make_pair(U,D));
   }
   vector<long long> dis(100000,LLONG_MAX);
   vector<long long> pat(100000,-1);
   vector<long long> dis2(100000,LLONG_MAX);
   vector<long long> pat2(100000,-1);
   calc(dis, pat, S,T);
   calc(dis2, pat2, T,S);
   //cout << pat[T] << "*" << pat2[S]<<endl;
   long long ans = pat[T]*pat2[S];
   long long dist = dis[T];
   for(int i = 0 ; i < N; i++){
      if(dis[i]*2 == dist){
         long long pp = pat[i]*pat2[i];
         pp %= MOD;
         //cout << "- " << pp*pp << endl;
         ans -= pp*pp;
         ans %= MOD;
      }
   }
   for(int i=0; i<N; i++){
      for(int j =0; j < (int)edge[i].size(); j++){
         int u = i;
         int v = edge[i][j].first;
         long long d = edge[i][j].second;
         ///cout <<u <<", "<< v << " : "<<  d << " " << dis[u] << " " << dis2[v] << " " <<endl;
         if( d+dis[u]+dis2[v] == dis[T] ){
            if( d+dis[u] <= dis2[v] || dis2[v]+d <= dis[u] ){
               //do nothing
            }
            else{
               long long pp = pat[u]*pat2[v];
               ////cout << pp << endl;
               pp %= MOD;
               ans -= pp*pp;
               //cout << "- " << pp*pp << endl;
               ans %= MOD;
            }
         }
      }
   }
   if(ans<0){
      ans+=MOD;
   }
   cout << ans << endl;
}
