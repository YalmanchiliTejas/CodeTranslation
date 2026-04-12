#include<iostream>
#include<vector>

using namespace std;

int main(){
  int a,b;
  char A,B;
  string C;

  cin >>a >>b ;
  vector< vector<char> > c(a,vector<char>(b));
  for(int i = 0 ; i < a; i++){
    for(int j = 0; j< b; j++){
      cin >> c[i][j];
    }
  }
  for(int i = 0; i< c.size() ;i++){
    int f = 0;
    for(int j = 0 ;j < c[0].size(); j++){
      if(c[i][j] == '#') f= 1;
    }
    if(f == 0){
      c.erase(c.begin() + i);
      i--;
    }
  }
  for(int j = 0; j< c[0].size() ;j++){
    int f = 0;
    int i;
    for(i = 0 ;i < c.size(); i++){
      if(c[i][j] == '#') f= 1;
    }
    if(f == 0){
      for(int k = 0 ; k < c.size(); k++){
        c[k].erase(c[k].begin()+j);
      }
      j--;
    }
  }
  for(int i = 0 ; i< c.size();i++){
    for(int j = 0 ; j< c[0].size(); j++){
      cout << c[i][j];
    }
    cout << endl;
  }
}
