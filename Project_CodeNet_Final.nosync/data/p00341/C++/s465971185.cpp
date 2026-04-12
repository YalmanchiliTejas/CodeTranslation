#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
  int edge[12];
  for(int i=0; i<12; i++)cin>>edge[i];
  
  sort(edge,edge+12);
  
  if(edge[0]==edge[3] && edge[4]==edge[7] && edge[8]==edge[11])cout<<"yes"<<endl;
  else cout<<"no"<<endl;
  
  return 0;
}
