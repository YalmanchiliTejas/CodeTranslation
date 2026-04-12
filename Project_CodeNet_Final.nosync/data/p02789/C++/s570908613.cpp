#include<iostream>
#include<fstream>
using namespace std;

int main(){
  //ifstream in("input.txt");
  //cin.rdbuf(in.rdbuf());
  
  int N,W;
  cin>>N>>W;
  cout<<(N==W? "Yes":"No")<<endl;
}
