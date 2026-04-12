#include <iostream>

#define H 9
#define W 9

bool endCheck(int h, int w, const bool A[H][W]){
  for(int i=0; i<=h; i++){
    for(int j=0; j<=w; j++){
      if(A[i][j]) return false;
    }
  }
  return true;
}

bool solve(int h, int w, int nowh, int noww, bool A[H][W]){
  A[nowh][noww] = false;
  if(h==nowh and w==noww)
    return endCheck(h, w, A);

  bool ret = false;
  if(nowh<h && A[nowh+1][noww]){
    bool T[H][W];
    for(int i=0; i<=h; i++){
      for(int j=0; j<=w; j++){
	T[i][j] = A[i][j];
      }
    }
    ret |= solve(h, w, nowh+1, noww, T);
  }
  if(noww<w && A[nowh][noww+1]){
    bool T[H][W];
    for(int i=0; i<=h; i++){
      for(int j=0; j<=w; j++){
	T[i][j] = A[i][j];
      }
    }
    ret |= solve(h, w, nowh, noww+1, T);
  }

  /*
  for(int i=0; i<=h; i++){
    for(int j=0; j<=w; j++){
      std::cout << A[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  */
  return ret;
}

int main(void){
  int h, w;
  bool A[H][W] = {};
  std::cin >> h >> w;
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      char c;
      std::cin >> c;
      if(c=='#') A[i][j] = true;
    }
  }

  if(solve(h-1, w-1, 0, 0, A)){
    std::cout << "Possible" << std::endl;
  }else{
    std::cout << "Impossible" << std::endl;
  }
  
  return 0;
}