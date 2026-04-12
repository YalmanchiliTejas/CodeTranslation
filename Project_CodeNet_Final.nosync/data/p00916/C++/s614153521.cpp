#include <iostream>
#include <algorithm>

using namespace std;

int xl[104], yl[104];
int l[50], t[50], r[50], b[50];
int rectanglesc[104][104];
int n;

void dfs(int i, int j, int ni, int nj, int cat){
    rectanglesc[i][j] = cat;

    bool rkabe = false;
    if(i < ni - 1 && rectanglesc[i+1][j] == -1){
      for(int k = 0 ; k < n ; k++){
        if(l[k] == xl[i+1] && b[k] <= yl[j] && yl[j+1] <= t[k]){rkabe = true;}
        if(r[k] == xl[i+1] && b[k] <= yl[j] && yl[j+1] <= t[k]){rkabe = true;}
      }
    }else{rkabe = true;}
    if(!rkabe){ dfs(i+1, j, ni, nj, cat); }

    bool bkabe = false;
    if(j > 0 && rectanglesc[i][j-1] == -1){
      for(int k = 0 ; k < n ; k++){
        if(t[k] == yl[j] && l[k] <= xl[i] && xl[i+1] <= r[k]){bkabe = true;}
        if(b[k] == yl[j] && l[k] <= xl[i] && xl[i+1] <= r[k]){bkabe = true;}
      }
    }else{bkabe = true;}
    if(!bkabe){ dfs(i, j-1, ni, nj, cat); }

    bool lkabe = false;
    if(i > 0 && rectanglesc[i-1][j] == -1){
      for(int k = 0 ; k < n ; k++){
        if(l[k] == xl[i] && b[k] <= yl[j] && yl[j+1] <= t[k]){lkabe = true;}
        if(r[k] == xl[i] && b[k] <= yl[j] && yl[j+1] <= t[k]){lkabe = true;}
      }
    }else{lkabe = true;}
    if(!lkabe){ dfs(i-1, j, ni, nj, cat); }

    bool tkabe = false;
    if(j < nj - 1 && rectanglesc[i][j+1] == -1){
      for(int k = 0 ; k < n ; k++){
        if(t[k] == yl[j+1] && l[k] <= xl[i] && xl[i+1] <= r[k]){tkabe = true;}
        if(b[k] == yl[j+1] && l[k] <= xl[i] && xl[i+1] <= r[k]){tkabe = true;}
      }
    }else{tkabe = true;}
    if(!tkabe){ dfs(i, j+1, ni, nj, cat); }
}

int main(void){
  for(;;){
    for(int i = 0; i < 104 ; i++){
      for(int j = 0; j < 104 ; j++){
        rectanglesc[i][j] = -1;
      }
    }
    cin >> n;
    if(n == 0){ return 0; }
    int xs[2 * n + 2], ys[2 * n + 2];
    for(int i = 0 ; i < n ; i++){
      cin >> l[i] >> t[i] >> r[i] >> b[i];
      xs[2 * i] = l[i];  xs[2 * i + 1] = r[i];
      ys[2 * i] = t[i];  ys[2 * i + 1] = b[i];
    }
    xs[2 * n] = -1;  xs[2 * n + 1] = 1000001;
    ys[2 * n] = -1;  ys[2 * n + 1] = 1000001;
    sort(xs, xs + 2 * n + 2);
    sort(ys, ys + 2 * n + 2);
    int xn = 0;
    int yn = 0;

    xl[0] = xs[0]; yl[0] = ys[0];
    for(int i = 1 ; i <= 2 * n + 1 ; i++){
      if(xl[xn] != xs[i]){
        xn++; xl[xn] = xs[i];
      }
      if(yl[yn] != ys[i]){
        yn++; yl[yn] = ys[i];
      }
    }
    int cat = 0;
    for(int i = 0; i < xn ; i++){
      for(int j = 0 ; j < yn ; j++){
        if(rectanglesc[i][j] == -1){
          dfs(i,j,xn,yn,cat);
          cat++;
        }
      }
    }

    cout << cat << endl;
  }
}
