#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int l[55],t[55],r[55],b[55];
ll ma[200][200];
int used [200][200];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};


void dfs(int x,int y,ll k){
  if(x<0||200<=x||y<0||200<=y)return;
  if(used[x][y]||ma[x][y]!=k)return;
  used[x][y]=1;
  for(int i=0;i<4;i++)
    dfs(x+dx[i],y+dy[i],k);
}

int main(){
  int n;
  while(cin>>n,n){
    fill_n(*ma,200*200,0);
    fill_n(*used,200*200,0);
    vector<int> tx,ty;
    for(int i=0;i<n;i++){
      cin>>l[i]>>t[i]>>r[i]>>b[i];
      tx.push_back(l[i]);
      tx.push_back(r[i]);
      ty.push_back(t[i]);
      ty.push_back(b[i]);
    }
    sort(tx.begin(),tx.end());
    sort(ty.begin(),ty.end());

    map<int,int> mp[2];
    for(int i=0;i<tx.size();i++){
      mp[0][tx[i]]=i+1;
      mp[1][ty[i]]=i+1;
    }

    for(int i=0;i<n;i++){
      l[i]=mp[0][l[i]];
      r[i]=mp[0][r[i]];
      t[i]=mp[1][t[i]];
      b[i]=mp[1][b[i]];

      ll k=1LL<<i;
      ma[l[i]][b[i]]+=k;
      ma[l[i]][t[i]]-=k;
      ma[r[i]][b[i]]-=k;
      ma[r[i]][t[i]]+=k;
    }

    for(int i=0;i<200;i++)
      for(int j=1;j<200;j++)
	ma[i][j]+=ma[i][j-1];

    for(int i=0;i<200;i++)
      for(int j=1;j<200;j++)
	ma[j][i]+=ma[j-1][i];

    int ans=0;
    for(int i=0;i<200;i++)
      for(int j=0;j<200;j++){
	if(used[i][j])continue;
	ans++;
	dfs(i,j,ma[i][j]);
      }
    cout<<ans<<endl;
  }
  return 0;
}

