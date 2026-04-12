#include<iostream>
#include<string>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
 
  string a;
  if(n==m) a = "Yes";
  else     a = "No";

  cout << a << endl;
  return 0;
}
