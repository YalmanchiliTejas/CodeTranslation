#include <iostream>
#include <algorithm>
using namespace std;
int main(){
        int a,b,c,x,y;
        cin >> a>> b>>c>> x >>y;
        int p=max(x,y);int ans=1000000000;
        for(int i=0; i<=2*p; i+=2) {
          if((x-(i/2))>=0&&(y-(i/2))>=0){
            ans=min(ans,i*c+(x-(i/2))*a+(y-(i/2))*b);
          }
          else if((x-(i/2))<0&&(y-(i/2))>=0){
             ans=min(ans,i*c+(y-(i/2))*b);
          }
          else if((x-(i/2))>=0&&(y-(i/2))<0){
            ans=min(ans,i*c+(x-(i/2))*a);
          }
          else{
            ans=min(ans,i*c);
          }
        }
        cout <<ans <<endl;
}
