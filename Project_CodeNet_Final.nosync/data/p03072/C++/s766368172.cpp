#include<iostream>
using namespace std;

int main(){

  int N;
  int i,j;

  cin >> N;

  int H[N];

  for(i=0; i<N; i++){
    cin >> H[i]; 
  }

  int answer=1;
  
  
  for(i=1; i<N; i++){
    int count=0;
    
    for(j=0; j<i; j++){
      if(H[i]>=H[j]){
	count++;
      }
    }

    if(count==i){
      answer++;
    }

    count=0;
  }
  
  cout << answer << endl;
  
}