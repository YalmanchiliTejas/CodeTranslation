#include<iostream>
using namespace std;
int main(){
  int n,a,b,c,x;
  while(cin >>n>>a>>b>>c>>x,n|a|b|c|x){
    int r[10000] = {0},tab[10001][2] = {0};
    tab[0][0] = x;
    for(int i=0; i<n; i++){cin>>r[i];}
    for(int i=0; i<10000; i++){tab[i+1][0] = (tab[i][0]*a+b)%c;}
    for(int i=0,at=-1; i<n; i++){
      int nat = at;
      for(int j=nat+1; j<10001; j++){
	if(tab[j][0] == r[i]){
	  if(at == nat){at = j;}
	  tab[j][1] = i+1;
	}
      }
      if(nat == at){break;}
    }
    int ans = -1;
    for(int i=0; i<10001; i++){if(tab[i][1] == n){ans = i;break;}}
    cout <<ans<<endl;
  }
  return 0;
}