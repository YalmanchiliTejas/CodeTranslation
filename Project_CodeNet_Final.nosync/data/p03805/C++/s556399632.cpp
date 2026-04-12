#include<bits/stdc++.h>
#define INF 1e12

using namespace std;
typedef long long int ll;

int main()
{
   int N,M; cin >> N >> M;
   vector<vector<bool>>G(N,vector<bool>(N,false));
   for(int i = 0; i < M; i++)
   {
       int a,b; cin >> a >> b;
       G[a-1][b-1] = true;
       G[b-1][a-1] = true;
   }
   vector<int>V(N);
   for(int i = 0; i < N; i++) V[i] = i;
   int ans = 0;
   do
   {
       bool f = true;
       for(int i = 0; i < N-1; i++)
       {
           if(G[V[i]][V[i+1]] == false) f = false;
       }
       if(f) ans++;
   }while(next_permutation(V.begin()+1,V.end()));
   cout << ans << endl;
}