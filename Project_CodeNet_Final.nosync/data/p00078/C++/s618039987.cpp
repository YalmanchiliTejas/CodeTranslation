#include <iostream>

#define N 15

using namespace std;

void Mahou(int);

main(){
  int n;
  while(1){
    cin >> n;
    if(n==0) break;
    Mahou(n);
  }
  return 0;
}

void Mahou(int n){
  int d[N][N];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      d[i][j]=-1;
    }
  }
  int x=n/2, y=n/2+1;
  int count=1;
  d[y][x]=count;
  y++;
  x++;
  count++;
  while(count<=n*n){
    while(1){
      if(y>=0 && y<n){
	if(x>=0 && x<n){
	  if(d[y][x]==-1){
	    break;
	  }else{
	    y++;
	    x--;
	  }
	}else{
	  if(x<0){
	    x=n-1;
	  }else{
	    x=0;
	  }
	}
      }else{
	if(y<0){
	  y=n-1;
	}else{
	  y=0;
	}
      }
    }
    d[y][x]=count++;
    y++;
    x++;
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      printf("%4d", d[i][j]);
    }
    cout << endl;
  }
}