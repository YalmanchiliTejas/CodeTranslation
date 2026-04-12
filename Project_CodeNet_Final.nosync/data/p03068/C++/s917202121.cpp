#include <iostream>
#include <string>

using namespace std;

int main(){
  int n;
  string s;
  int v;
  cin >> n >> s >> v;

  char str = s.at(v-1);

  for(int i=0; i<n; i++){
    if(s.at(i) != str){
      s.at(i) = '*';
    }
  }
  cout << s;
}
