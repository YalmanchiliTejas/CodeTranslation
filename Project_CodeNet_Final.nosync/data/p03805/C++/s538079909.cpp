#include <bits/stdc++.h>
using namespace std;
#define FOR(i,nn) for(int i=0;i<nn;i++)
#define MOD 1000000007
typedef long long ll;
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}else{return 0;}}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}else{return 0;}}
template <class T> inline T GCD(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template <class T> inline T LCM(T a,T b){return a*b/GCD(a,b);}

int n,m,ans=0;
vector<int> v[10];


void dfs(int g,bool r[]){
  int cnt=0;
  FOR(i,10){
    if(r[i]){
      cnt++;
    }
  }
  
  if(cnt==n){
    ans++;
    return;
  }
  FOR(i,v[g].size()){
    if(!r[v[g][i]]){
      r[v[g][i]]=1;
      dfs(v[g][i],r);
      r[v[g][i]]=0;
    }
  }
}

int main(){
    cin >> n >> m;
    int a[100],b[100];
    bool reached[10]={0};
    FOR(i,m){
      cin >> a[i] >> b[i];
      v[a[i]].push_back(b[i]);
      v[b[i]].push_back(a[i]);
    }
    reached[1]=1;
    dfs(1,reached);

    cout << ans << endl;
}