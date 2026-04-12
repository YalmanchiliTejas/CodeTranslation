#include<iostream>
#include<string>
using namespace std;
int N_MAX = 100000;
int main()
{
  int n,i,j,res;
  int p[N_MAX],c[4][2]={{0,0},{0,1},{1,0},{1,1}};
  string s;
  cin >> n >> s;
  for(i=0;i<4;i++){
    p[0]=c[i][0];
    p[1]=c[i][1];
    for(j=1;j<=n-2;j++){
      if(s[j]=='o')
        p[j+1]=(p[j]+p[j-1])%2;
      else
        p[j+1]=1-(p[j]+p[j-1])%2;
    }
    if(s[n-1]=='o'&&(p[n-2]+p[n-1]+p[0])%2==1
       || s[n-1]=='x'&&(p[n-2]+p[n-1]+p[0])%2==0
       || s[0]=='o'&&(p[n-1]+p[0]+p[1])%2==1
       || s[0]=='x'&&(p[n-1]+p[0]+p[1])%2==0)
      continue;
    for(j=0;j<n;j++){
      if(p[j]==0)
        cout << "S";
      else
        cout << "W";
    }
    cout << endl;
    return 0;
  }
  cout << "-1" << endl;
  return 0;
}