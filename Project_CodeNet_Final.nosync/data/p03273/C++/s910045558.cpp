#include<bits/stdc++.h>
using namespace std;

int main(){
  int h,w,i,j;
  cin>>h>>w;
  string a[h];
  for(i=0;i<h;i++){
    cin>>a[i];
  }
  int cnt=0;
  string p[h];
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(a[i][j]=='#'){
        p[cnt]=a[i];
        cnt++;
		break;
      }
    }
  }
  int flg;
  for(i=0;i<w;i++){
	flg=0;
    for(j=0;j<cnt;j++){
      if(p[j][i]=='#'){
		  flg++;
		  break;
      }
    }
	if(!flg){
		for(j=0;j<cnt;j++){
			p[j]==p[j].erase(i,1);
		}
	w--;
	i--;
	}
  }
  for(i=0;i<cnt;i++){
    cout<<p[i]<<endl;
  }
}