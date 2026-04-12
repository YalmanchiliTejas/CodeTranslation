#include <iostream>

using namespace std;

int main(){
    int x,y,z;
    int side=0,i=0;
    cin>>x>>y>>z;
while(1){
    side+=z;
    if(side>x) {
        i--;
        break;
    }
    side+=y;
    if(side>=x) break;
    i++;
}
    cout<<i<<endl;
  return 0;
}