#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int h,w;
   cin>>h>>w;
   vector<string> a(h);
   for(int i=0;i<h;i++){
      cin>>a.at(i);
   }
   vector<bool> y(h,false),x(w,false);
   for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
         if(a.at(i).at(j)=='#'){
            y.at(i)=true;
            x.at(j)=true;
         }
      }
   }
   for(int i=0;i<h;i++){
      if(y.at(i)){
         for(int j=0;j<w;j++){
         if(x.at(j)){
            cout<<a.at(i).at(j);
         }
         }
         cout<<endl;
      }
   }
}
