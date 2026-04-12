#include <bits/stdc++.h>
using namespace std;

int main(){
  
 int N, count = 1;
 cin >> N;
  vector<int>H(N);

 for(int i = 0; i < N; i++){
  cin >> H.at(i); 
 }

 for(int i = 1; i < N; i++){
 
   for(int x = 0; x < i ; x++){
    
     if(H.at(x) > H.at(i)){
     break;
    }else if(x + 1 == i){
     count++;
     }
   
   }
	
 
 }
 
  cout << count << endl;
  
 }