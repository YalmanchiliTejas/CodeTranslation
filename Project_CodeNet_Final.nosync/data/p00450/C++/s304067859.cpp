#include<cstdio>
#include<stack>
#include<algorithm>
#define REP(i,a,n) for(int i = a;i < n;i++)
#define rep(i,n) REP(i,0,n)
#define fir first
#define sec second
using namespace std;
int main(void){
   stack<pair<int,int> >go;
   int n;
   pair<int,int>in;
   pair<int,int>out;

   while(scanf("%d",&n),n){
      int col;scanf("%d",&col);
      in.fir = col; in.sec = 1;
      rep(i,n-1){
         scanf("%d",&col);
         if(in.fir == col) in.sec += 1;
         else{
            if(i%2 == 0){
               if(go.empty()){
                  in.fir = col;
                  in.sec += 1;
               }
               else{
                  out = go.top(); go.pop();
                  in.fir = col;
                  in.sec += out.sec+1;
               }
            }
            else{
               go.push(in);
               in.fir = col; in.sec = 1;
            }
         }
      }
      go.push(in);

      int cnt = 0;
      while(go.size()){
         out = go.top(); go.pop();
         if(out.fir == 0) cnt += out.sec;
      }
      printf("%d\n",cnt);
   }
}