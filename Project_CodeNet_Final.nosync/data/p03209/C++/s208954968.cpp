#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

ll rec(ll L, ll X){
  
  if( L == 0){ return 1;}
  
  else{
  ll hight = (1LL << (L + 1)) - 3;
  ll number = ( 1LL << (L) ) - 1;
  
  
  if( X == 1){ return 0;}
  else if( X <= hight + 1){
    return rec( L - 1, X - 1);}
  else if( X == hight + 2){
    return number + 1 ;}
  else if( X <= 2* hight + 2 ){
    return number + rec( L - 1, X - hight - 2) + 1;}
  else if( X == 2 * hight + 3){
    return 2*number + 1;} }
}
      
    


int main(){
ll N,X; cin >> N >> X;
  
  cout << rec(N,X) << endl; return 0;}
    
  
