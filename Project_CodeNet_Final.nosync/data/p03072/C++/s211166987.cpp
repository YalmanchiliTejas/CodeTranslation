#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int maximum;

int max_count(std::vector<int> H, int i, int maximum){
  if(i == H.size()){
	return 0;
  }

  if(maximum <= H.at(i)){
	maximum = H.at(i);
	return 1+ max_count(H, i+1, maximum);
  }
  else{
    return max_count(H, i+1, maximum);
  }
}

int main(){
  int i=0;
  int maximum=0;
  int N;
  cin >> N;
  vector<int> H(N);
  
  for(int i=0; i<N; i++){
	cin >> H.at(i);
  }

  cout << max_count(H, i=0, maximum) << endl;

  return 0;
}


