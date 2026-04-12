#include <bits/stdc++.h>
using namespace std;

long double func(long long n,long long x){
  if(n == 1){return x;}
  else{return func(n-1,x*n);}
}
            
int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>> a(n+1,vector<int>(0,0));
  for(int i=0;i < m;i++){
    int x, y;
    cin >> x >> y;
    a.at(x).push_back(y);
    a.at(y).push_back(x);
  }
  vector<int> b(n-1);
  for(int i=0;i <n-1;i++){
    b.at(i) = i+2;
  }
  long double x = func(n-1,1);
  long double sum = 0;
  for(int i=0;i < x;i++){
  	next_permutation(b.begin(),b.end());
    int check = 0;
    for(int l=0;l < (int)a.at(1).size();l++){
      if(a.at(1).at(l) == b.at(0)){check = 1;}
    }
    if(check == 1){
      int buf = 1;
      for(int j=1;j < n-1;j++){
     	 int check_2 = 0;
        //cout << a.at(b.at(j-1)).size() << endl;
      	for(int l=0;l < (int)a.at(b.at(j-1)).size();l++){
          //cout << a.at(b.at(j-1)).at(l) << b.at(j) << endl;
      		if(a.at(b.at(j-1)).at(l) == b.at(j)){check_2 = 1;}
      	}
      	if(check_2 == 1){buf++;}
      }
      if(buf == n-1){sum++;}
 	 }
  }
  cout << sum << endl;
}