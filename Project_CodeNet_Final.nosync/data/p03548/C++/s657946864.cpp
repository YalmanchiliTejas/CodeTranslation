#include<iostream>
using namespace std;
int main(){
 int x,y,z;
 cin>>x>>y>>z;
 int i=0;

 while(i*(y+z)+z<=x){
  i++;
 }
 cout<<i-1<<endl;
}
