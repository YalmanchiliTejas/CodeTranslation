#include <iostream>
#include <array>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef  pair<int,int> P;
typedef long long LL;

const LL  INF=1<<31;
const LL MOD=1000000007;



int main(){
     int n,m;
     cin>>n>>m;
     int sowa=n*(1+n)/2;
     int p[50][50]={0};
     for(int i=0;i<m;++i){
          int a,b;
          cin>>a>>b;
          p[a][b]=1;
          p[b][a]=1;
     }
     int ans=0;
     vector<int> v(n);
     for(int i=0;i<n;++i){
          v[i]=i+1;
     }
     do{
          int all=1;
          for(int i=0;i<n-1;++i){
               if(p[v[i]][v[i+1]])all+=v[i+1];
          }
          if(all==sowa)ans++;
     }while(next_permutation(v.begin()+1,v.end()));
     
     cout<<ans<<endl;
}