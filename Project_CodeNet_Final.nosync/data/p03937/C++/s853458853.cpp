#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
int H,W;
int A[10][10];
int main(){
	cin>>H;
	cin>>W;
	REP(i,H){
	    string s;
	    cin>>s;
	    REP(j,W){
	        if(s[j]=='.'){
	           A[i][j]=0;
	        }else{
	           A[i][j]=1;
	        }
	    }
	}
	int x=0;
	int y=0;
	A[0][0]=0;
	while(1){
	   if(x+1<H){
	      if(A[x+1][y]==1){
	         A[x+1][y]=0;
	         x++;
	         continue;
	      }
	   }
	   if(y+1<W){
	      if(A[x][y+1]==1){
	         A[x][y+1]=0;
	         y++;
	         continue;
	      }
	   }
	   break;
	}
	bool check=false;
	if(x==H-1&&(y==W-1)){
	   bool c=true;
	   REP(i,H){
	       REP(j,W){
	           if(A[i][j]==1)c=false;
	       }
	   }
	   check=c;
	}
	if(check){
	   cout<<"Possible"<<endl;
	}else{
           cout<<"Impossible"<<endl;
        }
	return(0);
}