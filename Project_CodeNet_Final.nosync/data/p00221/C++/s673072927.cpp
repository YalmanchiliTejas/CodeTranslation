#include<bits/stdc++.h>
using namespace std;
typedef struct{
  int right;
  int left;
  int daturaku;
}Player;
main(){
  int m,n;
  Player p[10005];
  char sengen[10];
  while(1){
    cin>>m>>n;
    if(m==0&&n==0)break;
    for(int i=1;i<=m;i++){
      p[i].left=i-1;
      p[i].right=i+1;
      p[i].daturaku=0;
    }
    p[1].left=m;
    p[m].right=1;
    int menber=m;
    int now=1;
    for(int i=1;i<=n;i++){
      cin>>sengen;
      if(menber==1){
	continue;
      }
      bool deff=false;
      int beki=log10(i)+1;
      int num=atoi(sengen);
      if(strcmp("Fizz",sengen)==0){
	if(i%3!=0||i%15==0){
	  deff=true;
	}
      }
      else if(strcmp("Buzz",sengen)==0){
	if(i%5!=0||i%15==0){
	  deff=true;
	}
      }
      else if(strcmp("FizzBuzz",sengen)==0){
	if(i%15!=0){
	  deff=true;
	}
      }
      else if(strlen(sengen)!=beki||num!=i||num%3==0||num%5==0){
	deff=true;
      }
      if(deff==true){
	p[p[now].left].right=p[now].right;
	p[p[now].right].left=p[now].left;
	p[now].daturaku=1;
	menber--;
      }
      now=p[now].right;
    }
    bool nidome=false;
    for(int i=1;i<=m;i++){
      if(p[i].daturaku==0){
	if(nidome==true){
	  cout<<' ';
	}
	else{
	  nidome=true;
	}
	cout<<i;
      }
    }
    cout<<endl;
  }
}