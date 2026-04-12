#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

int main() {
  int h, w;
  vector <vector <char> > A;

  int i,j, counter; 

  cin >> h >> w; 
  
  A.resize(h);
  for(i=0;i<h;i++){
    A[i].resize(w);
  }
  counter=0;
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      cin >> A[i][j];
      if(A[i][j]=='#')
	counter++;
    }
  }

  if(counter>w+h-1){
    cout << "Impossible" <<endl;
    return 0;
  }
  
  i=0; j=0;
  //  printf("(%d,%d)%c\n",i,j,A[i][j]);    
  
  do{
    if(A[i][j+1]=='#'){
      if(A[i+1][j]!='#'){	
	j++;
      }else{
	cout << "Impossible" << endl;
	return 0;
      }
    }else if(A[i+1][j]=='#'){
      i++; 
    }else{
      cout << "Impossible" << endl;
      return 0;
    }
    //    printf("(%d,%d)%c\n",i,j,A[i][j]);
  }while(i<h-1 && j<w-1);


  if(i==h-1){
    do{      
      if(A[i][j+1]=='#'){
	j++;
      }else{
	cout << "Impossible" << endl;
	return 0;
      }
    }while(j!=w-1);
  }else{
    do{      
      if(A[i+1][j]=='#'){
	i++;
      }else{
	cout << "Impossible" << endl;
	return 0;
      }
    }while(i!=h-1);
  }

  cout << "Possible" << endl;
  return 0;  
}
	
  
