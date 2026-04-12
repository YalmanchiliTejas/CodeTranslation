#include <iostream>
#include <algorithm>

using namespace std;

int N;
string P;
string m1;

string f(string a, string b){
  if(a == "T" && b == "F"){
    return "F";
  }
  return "T";
}

int main(){
  cin >> N;
  cin >> m1;
  for(int i=0;i<N-1;i++){
    cin >> P;
    m1 = f(m1, P);
  }

  cout << m1 << endl;
  return 0;
}

