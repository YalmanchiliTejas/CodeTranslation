#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	int N,M,sw = 0;
  cin >> N >> M;
  vector<vector<char>> a(N,vector<char>(M));
  vector<vector<int>> b(N,vector<int>(M,0));
  froop1(0,N){
    for(int j = 0;j < M;j++){
      cin >> a.at(i).at(j);
    }
  }
  
	froop1(0,N){
      for(int j = 0;j < M;j++){
        if(a.at(i).at(j) == '#'){
          sw = 1;
          break;
        }
      }
      if(sw == 0){
      for(int j = 0;j < M;j++){
        b.at(i).at(j) = 1;
      }
      }
      sw = 0;
	}
  	froop1(0,M){
      for(int j = 0;j < N;j++){
        if(a.at(j).at(i) == '#'){
          sw = 1;
          break;
        }
      }
      if(sw != 1){
      for(int j = 0;j < N;j++){
        b.at(j).at(i) = 1;
      }
      }
      sw = 0;
	}
  
  froop1(0,N){
   for(int j = 0;j < M;j++){
    if(b.at(i).at(j) == 0){
      cout << a.at(i).at(j);
      sw = 1;
    }
   }
    if(sw == 1){
    cout << endl;
      sw = 0;
    }
  }
return 0;
}