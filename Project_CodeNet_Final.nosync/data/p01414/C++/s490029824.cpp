#include <iostream>
#include <set>
#include <queue>
using namespace std;
int N;
int H[16],W[16];
int ne[16][7][7] = {};
int ok[16][7][7][3] = {};
int dist[1<<16] = {};
char C[7][7];

bool in(int x,int y){
    return 3<=x && x<=6 && 3<=y && y<=6;
}

int to_line(int x,int y){
    return 4*(x-3)+(y-3);
}

int main(){
   cin >> N;
   for(int i=0;i<N;i++) cin >> H[i] >> W[i];
   for(int i=3;i<7;i++){
      for(int j=3;j<7;j++){
         cin >> C[i][j];
      }    
   }
   for(int i=0;i<7;i++){
      for(int j=0;j<7;j++){
         for(int k=0;k<N;k++){
            ne[k][i][j] = -1;
            for(int l=0;l<3;l++) ok[k][i][j][l] = 0;
            int T = (1<<16)-1;
            for(int r=0;r<H[k];r++){
               for(int c=0;c<W[k];c++){
                  if(in(i+r,j+c)){
                     T ^= (1<<to_line(i+r,j+c));
                     if(C[i+r][j+c]=='R'){ok[k][i][j][1] ^= (1<<to_line(i+r,j+c)); ok[k][i][j][2] ^= (1<<to_line(i+r,j+c));}
                     if(C[i+r][j+c]=='B'){ok[k][i][j][0] ^= (1<<to_line(i+r,j+c)); ok[k][i][j][2] ^= (1<<to_line(i+r,j+c));}
                     if(C[i+r][j+c]=='G'){ok[k][i][j][1] ^= (1<<to_line(i+r,j+c)); ok[k][i][j][0] ^= (1<<to_line(i+r,j+c));}
                  }
               }
            }
            ne[k][i][j] = T;
         }
      }
   }
/*   for(int i=0;i<7;i++){
      for(int j=0;j<7;j++) cerr << ne[0][i][j] << " ";
      cerr << endl;
   }
*/   for(int i=0;i<(1<<16);i++) dist[i] = -1;
   dist[(1<<16)-1] = 0;
   queue<int> Q;
   Q.push((1<<16)-1);
   while(!Q.empty()){
      int S = Q.front(); Q.pop();
      for(int i=0;i<7;i++){
         for(int j=0;j<7;j++){
            for(int k=0;k<N;k++){
               for(int l=0;l<3;l++){
                  if((ne[k][i][j]==(1<<16)-1) || (S & ok[k][i][j][l])!=0) continue;
                  int T = (S & ne[k][i][j]);
                  if(dist[T]==-1){
                     dist[T] = dist[S]+1;
                     Q.push(T);
                  }
               }
            }
         }
      }
   }
   cout << dist[0] << endl;
}
