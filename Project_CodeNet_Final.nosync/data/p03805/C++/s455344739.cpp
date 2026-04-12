#include<bits/stdc++.h>
using namespace std ;

int main(){
  int n,m ; cin >> n >> m ;
  vector<vector<bool>> pass(n,vector<bool>(n,false)) ;
  for(int i=0;i<n;i++) pass.at(i).at(i) = true ;
  for(int i=0;i<m;i++){
    int a,b ;
    cin >> a >> b ;
    pass.at(a-1).at(b-1) = pass.at(b-1).at(a-1) = true ;
  }
  vector<int> num ;
  for(int i=0;i<n;i++) num.push_back(i) ;
  int ans = 0 ;
  do{
    if(num.at(0)!=0) break ;
    bool check = true ;
    for(int i=0;i<n-1;i++){
      if(!pass.at(num.at(i)).at(num.at(i+1))){
        check = false ;
        break ;
      }
    }
    if(check) ans++ ;
  }while(next_permutation(num.begin(),num.end())) ;
  cout << ans << endl ;
}