#include<iostream>
#include<vector>

using namespace std;
int dy[]={0, 1, 0, -1};
int dx[]={1, 0, -1, 0};// right, down, ...
string ans="Impossible";
int H, W;
char a[10][10];
int F=0;

void rec(int i, int j){

   a[i][j]='.';
   if(i==H-1&&j==W-1){
      F=1;
      return;
   }else{
      int c=0;
      for(int k=0; k<2; k++){
         int ni=i+dy[k];
         int nj=j+dx[k];
         if(!(0<=ni&&ni<H&&0<=nj&&nj<W)) continue;
         if(c==0&&a[ni][nj]=='#'&&F==0){
            c++;
            rec(ni, nj);
         }
      }
   }
}
int main(){

   cin>> H>> W;
   for(int i=0; i<H; i++){
      for(int j=0; j<W; j++){
         cin>> a[i][j];
      }
   }

   rec(0, 0);

   int f=0;
   for(int i=0; i<H; i++){
      for(int j=0; j<W; j++){
         f|=(a[i][j]=='#');
      }
   }

   cout<< (f? "Impossible": "Possible")<< endl;

   return 0;
}
