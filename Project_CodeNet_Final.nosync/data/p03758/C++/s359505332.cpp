#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int>P;

int N;


int main(){
  cin >> N;
  vector<P>res;
  string s = "";
  for(int i=0;i<N;i++){
    s += "0";
  }
  for(int i=0;i<N;i++){
    s[i] = '1';
    for(int j=i+1;j<N;j++){
      s[j] = '1';
      cout << "? " << s << endl;
      int d;  cin >> d;
      if(d){
	res.push_back(P(i, j));
      }
      s[j] = '0';
    }
    s[i] = '0';
  }

  cout << "!";
  for(auto &r: res){
    cout << " (" << r.first << "," <<  r.second << ")";
  }
  cout << endl;
}
