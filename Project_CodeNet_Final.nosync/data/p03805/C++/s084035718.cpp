#include <bits/stdc++.h>
using namespace std;
int N, ans=0;

int Sosu(int x){
  switch(x){
    case 1: return 2;
    case 2: return 3;
    case 3: return 5;
    case 4: return 7;
    case 5: return 11;
    case 6: return 13;
    case 7: return 17;
    case 8: return 19;
  }
}

int Loop(int Point, int Bridge[], int Posi){
  Point/=Sosu(Posi);
  if(Point==1){
    ans++;
    return 0;
  }
  for(int i=1 ; i<N+1 ; i++)
    if((Point%Sosu(i))+(Bridge[Posi]%Sosu(i))==0){
      //cout << Posi << "->" << i << endl;
      Loop(Point, Bridge, i);
    }
  return 0;
}

int main(){
  int M;
  cin >> N >> M;
  int Point=1, Bridge[N+1];
  for(int i=1 ; i<N+1 ; i++){
    Point*=Sosu(i);
    Bridge[i]=1;
  }
  
  for(int i=0 ; i<M ; i++){
    int A, B;
    cin >> A >> B;
    Bridge[A]*=Sosu(B);
    Bridge[B]*=Sosu(A);
  }
  
  int Posi=1;
  Loop(Point, Bridge, Posi);
  cout << ans << endl;
}