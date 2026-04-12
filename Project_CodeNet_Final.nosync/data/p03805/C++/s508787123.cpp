#include <bits/stdc++.h>
using namespace std;

bool ch[9][9]={0};
int n,m,co=0;
int perm[8];
bool chp=0;

int main(){
  int i,j,a,b;
  cin >> n >> m;
  for(i=0;i<m;i++){
    cin >> a >> b;
    ch[a][b]++;
    ch[b][a]++;
  }

  for(i=0;i<n;i++)perm[i]=i+1;
  do{
    for(i=1;i<n;i++){
      if(chp==0&&ch[perm[i]][perm[i-1]]==0)chp++;
    }
    if(chp==0)co++;
    chp=0;
  }while(next_permutation(&perm[1],perm+n));
  cout << co << endl;
  return 0;
}
