#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int no,p,n,nok,ik;
  int j[31];
  int d[100];
  int ans[100];
  char c;
  for(int i=0;i<30;i++) j[i] = -1; 
  while(cin>>no>>c>>p){
    if(no==0&&p==0) break;
    ans[no] = p;
    d[no-1] = p;
    nok = no;
  }
  sort(d,d+nok,greater<int>());
  n = 0;
  for(int i=1;i<30;i++){
    while(j[i]==-1){
      if(j[i-1]!=d[n]){
	j[i] = d[n];
	n++;
      }
      else n++;
      if(n>nok){
	ik = i;
	break;
      }
    }
    if(n>nok) break;
  }
  while(cin>>no){
    for(int i=1;i<ik;i++){
      if(ans[no]==j[i]){
	cout << i  << endl;
	break;
      }
    }
  }
  return 0;
} 