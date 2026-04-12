#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
  int n;
  vector<int> sizearray;
  while(cin>>n&&n){
    sizearray.push_back(n);
  }
  for(int index=0;index<sizearray.size();index++){
    int size=sizearray[index];
    vector<vector<int> > Mat(size);
    for(int i=0;i<size;i++){
      Mat[i].resize(size);
    }
    int y=size/2+1,x=size/2;
    for(int i=1;i<=size*size;i++){
      if(Mat[y][x]){
        y=(y+1)%size;
        x=(x-1)<0?size-1:x-1;
      }
      Mat[y][x]=i;
      y=(y+1)%size;
      x=(x+1)%size;
    }


    for(int i=0;i<size;i++){
      for(int j=0;j<size;j++){
        cout<<setw(4)<<Mat[i][j];
      }
      cout<<endl;
    }
  }

}