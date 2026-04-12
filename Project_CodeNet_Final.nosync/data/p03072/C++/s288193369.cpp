#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main(int argc, char *argv[]) {
  /*
  cin>>x;
  cout<<x<<endl;
  */
  int i,j,n,m,l,c=0;
  cin>>n;
  cin>>m;
  c++;
  for(i=1;i<n;i++){
    cin>>l;
    if(m>l)
      continue;
    else{
      c++;
      m=l;
    }
  }
  cout<<c<<endl;
}
