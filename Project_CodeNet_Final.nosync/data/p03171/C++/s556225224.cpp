#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Game(vector< int > &element,int n)
{
     vector< vector < pair< ll,ll > > >   DP(n+2,vector< pair< ll,ll > > (n+1,make_pair(0,0)));
     for(int l=0;l<n;l++){
          for(int  i=1;i<=n-l;i++){
               int j = i+l;
               if(element[i-1]+ DP[i+1][j].second>element[j-1] + DP[i][j-1].second){
                    DP[i][j].first = element[i-1]+ DP[i+1][j].second;
                    DP[i][j].second = DP[i+1][j].first;
               }
               else{
                    DP[i][j].first = element[j-1] + DP[i][j-1].second;
                    DP[i][j].second = DP[i][j-1].first;
              }
          }
     }
     return DP[1][n].first - DP[1][n].second;
}
int main()
{
     //freopen("in.txt","r",stdin);
     int n;
     cin >> n;
     vector< int >  element(n);
     for(int i=0;i<n;i++)     cin >> element[i];
     ll ans = Game(element,n);
     cout << ans << endl;
}
