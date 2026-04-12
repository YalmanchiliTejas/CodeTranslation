#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y,z;
  scanf("%d %d %d",&x,&y,&z);
  x-=z;
  y+=z;
  cout<<x/y<<endl;
  return 0;
}
