#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <math.h>
#define rep(i,n) for(int i=0;i<=(n);i++)
using namespace std;


int main(){
  int n;cin>>n;
  if(n == 3 || n == 5 || n == 7){
    cout << "YES";
  }else{
    cout << "NO";
  }
  cout << endl;
}
