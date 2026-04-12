#include <cstdio>
#include <array>
#include <bitset>

using namespace std;

int func( int N, bool* h, bool* sw ){
  for(int i=1; i<N-1; i++){
    sw[i+1] = h[i]!=sw[i]^sw[i-1];
  }

  bool accept1 = sw[0]==sw[N-2]==h[N-1]^!sw[N-1];
  bool accept2 = sw[1]==sw[N-1]==h[0]  ^!sw[0];

  if( accept1&&accept2){
    for(int i=0; i<N; i++){
      if(sw[i]){
        printf("%c",'S') ;
      }
      else{
        printf("%c",'W') ;
      }
    }
    printf("\n") ;
    std::exit(0) ;
  }
}

int main( int argc, char *argv[] ){
  int N ;
  scanf("%d",&N) ;

  char* s  = new char[N] ;
  bool* h  = new bool[N] ;
  bool* sw = new bool[N] ;

  scanf("%s",s) ;

  for(int i=0; i<N; i++){
    h[i] = s[i]=='o';
  }

  sw[0] = true;  sw[1] = true;
  func( N, h, sw );
  sw[0] = true;  sw[1] = false;
  func( N, h, sw );
  sw[0] = false; sw[1] = true;
  func( N, h, sw );
  sw[0] = false; sw[1] = false;
  func( N, h, sw );

  printf("%d\n",-1) ;
}
