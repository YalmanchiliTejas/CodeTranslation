#include<functional>
#include<algorithm>
#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define pb push_back
#define int long long
using namespace std;
const int INF=1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


signed main(){
  string t,p;
  cin>>t>>p;
  int m[600005]={};
  int p1=0;
  for(int i=0;i<t.size();i++){
    if(t[i]==p[p1]){
      m[i]++;
      p1++;
      if(p1==p.size())break;
    }
  }
  if(p1!=p.size()){
    cout<<"no"<<endl;
    return 0;
  }
  int p2=p.size()-1;
  for(int i=t.size()-1;i>=0;i--){
    if(t[i]==p[p2]){
      m[i]++;
      p2--;
      if(p2==-1)break;
    }
  }

bool f=true;
for(int i=0;i<t.size();i++){
  if(m[i]==1){
    f=false;
    break;
  }
 }
cout<<(f?"yes":"no")<<endl;
return 0;
}