#include<stdio.h>
#include<string.h>
#include<list>

int main(){
  using namespace std;
  int i,n,m,ps;
  char opn[20],ans[20];
  bool ff,bf;
  list<int> player;
  list<int>::iterator it;
  do{
    scanf("%d %d",&m,&n);
    if(!m&&!n) break;
    for(i=0;i<m;i++) player.push_back(i+1);
    for(i=0,it=player.begin(),ps=m;i<n;i++){
      scanf("%s",opn);
      if(ps<2) continue;
      ff=(i+1)%3==0,bf=(i+1)%5==0;
      if(ff||bf){
	sprintf(ans,"%s%s",ff?"Fizz":"",bf?"Buzz":"");
      }else{
	sprintf(ans,"%d",i+1);
      }
      if(strcmp(ans,opn)){
	it=player.erase(it);
	ps--;
      }else{
	it++;
      }
      if(it==player.end()) it=player.begin();
    }
    it=player.begin();
    while(it!=player.end()){
      printf("%d",*it);
      it++;
      if(it!=player.end()) printf(" ");
    }
    printf("\n");
    player.clear();
  }while(1);
  return 0;
}