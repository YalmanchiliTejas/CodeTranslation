#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <ios>     // std::left, std::right
#include <iomanip> // std::setw(int), std::setfill(char)
using namespace std;


int main(){
  std::string s;
  cin>>s;
  if((s[0]!=s[1])||(s[0]!=s[2])||(s[1]!=s[2])){
    cout<<"Yes"<<"\n";
  }
  else{
    cout<<"No"<<"\n";
  }
return 0; 
}