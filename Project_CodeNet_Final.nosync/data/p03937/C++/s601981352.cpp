#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;
const int dx[]={1,0};
const int dy[]={0,1};
int main()
{
  int h,w,cnt=0;
  cin>>h>>w;
  vector<string> field(h);
  for(auto&& e: field) 
  {
    cin>>e;
  }

  for (int i = 0; i < h; ++i)
  {
    for (int j = 0; j < w; ++j)
    {
      if(field[i][j]=='#') cnt++;
      if(i==h-1||j==w-1) continue;
      if(field[i+1][j]=='#'&&field[i][j+1]=='#')
      {
        cout<<"Impossible"<<endl;
        return 0;
      }
    }
  }
  queue<pair<int,int>> q;
  q.push(make_pair(0,0));
  while(!q.empty())
  {
    int i=q.front().first,j=q.front().second;
    q.pop();
    if(field[i][j]=='.') continue;
    for (int k = 0; k < 2; ++k)
    {
      int ni=dx[k]+i,nj=dy[k]+j;
      if(ni<0||ni>=h||nj<0||nj>=w) continue;
      q.push(make_pair(ni,nj));
    }
    cnt--;
  }
  if(cnt==0) cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
  
}