#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

char a[10][10];
bool flag=false;
int H,W,need=0;

void dfs(int i,int j,int cnt) {
  if (i==H-1 && j==W-1 && cnt==need)
    flag=true;
  if (i+1<H && a[i+1][j]=='#')
    dfs(i+1,j,cnt+1);
  if (j+1<W && a[i][j+1]=='#')
    dfs(i,j+1,cnt+1);
}

int main() {
  cin>>H>>W;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cin>>a[i][j];
      if(a[i][j]=='#') need++;
    }
  }

  dfs(0,0,1);
  if (flag)
    cout<<"Possible"<<endl;
  else
    cout<<"Impossible"<<endl;
  return 0;
}