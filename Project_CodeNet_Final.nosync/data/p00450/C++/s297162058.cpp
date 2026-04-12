#include<iostream>
#include<cstdio>
#include<cassert>
#define F first
#define S second
#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
using namespace std;
typedef pair<int,bool> IB;
typedef pair<IB,int> P;//P(IB(cnt,1 or 0),prev)

int main(){
  int n;
  while(true){
    scanf("%d",&n);
    if(n == 0)break;
    P p[n+2];
    int now = 1,cnt = 0;
    rep(i,n+2)p[i] = P(IB(-1,false),-1);
    bool deb[n+2];

    for(int i=1;i<=n;i++){
      bool input;
      cin >> input;
      deb[i] = input;
      if(i == 1){
	p[i] = P(IB(1,input),-1);
	now = 1;
	continue;
      }
      
      /* odd */
      if(i%2 != 0){
	if(input == p[now].F.S){
	  p[now].F.F++;
	}	
	else{
	  p[i] = P(IB(1,input),now);
	  now = i;
	}
	continue;
      }

      /* even */
     
      if(input == p[now].F.S){
	p[now].F.F++;
      }
      else {
	p[now].F.F++;
	p[now].F.S = input;

	if(-1 != p[now].S){
	  p[p[now].S].F.F += p[now].F.F;	  
	  int post = p[now].S;
	  p[now] = P(IB(-1,false),-1);
	  now = post;
	}
      }
    }

   
    for(int i=1;i<=n;i++)if(!p[i].F.S && p[i].F.F != -1)cnt += p[i].F.F;
    cout << cnt << endl;
  }
  return 0;
}