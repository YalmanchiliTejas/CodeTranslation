#include<iostream>
#include<vector>

using namespace std;

int main(){
  int n;
  int temp_max=0;
  int num_ocean_view=0;
  
  cin >> n;
  
  vector<int> v(n);
  for (int i=0; i < n; i++){
    cin >> v[i];
  }
  
  
  for (int i=0; i < n; i++){
  	if (temp_max <= v[i]){
      num_ocean_view += 1;
      temp_max = v[i];
    }
  }

  cout << num_ocean_view << endl;

  return 0;
}