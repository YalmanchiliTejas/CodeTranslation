#include<iostream>
using namespace std;

int val(char a){
  if(a=='T')return 10;
  if(a=='J')return 11;
  if(a=='Q')return 12;
  if(a=='K')return 13;
  if(a=='A')return 14;
  return (int)(a-'0');
}

int main(){
  char t;
  string c[4][13];
  
  while(cin >> t,t!='#'){
    for(int i=0;i<4;i++)for(int j=0;j<13;j++)cin >> c[i][j];
    
    int ns=0,ew=0,prv = 0;
    for(int i=0;i<13;i++){
      int tr=0,ma=0,tid,mid,v;
      for(int j=0;j<4;j++){
	if(c[j][i][1] == t){
	  v = val(c[j][i][0]);
	  if(tr<v){
	    tr = v; tid = j;
	  }
	}
	if(c[j][i][1] == c[prv][i][1]){
	  v = val(c[j][i][0]);
	  if(ma<v){
	    ma = v; mid= j;
	  }
	}
      }      if(tr){
	prv = tid;
	if(tid&1)ew++;else ns++;
      }else{
	prv = mid;
	if(mid&1)ew++;else ns++;
      }
    }
    if(ns>ew)cout << "NS " << ns-6 << endl;
    else cout << "EW " << ew-6 << endl;
  }
}