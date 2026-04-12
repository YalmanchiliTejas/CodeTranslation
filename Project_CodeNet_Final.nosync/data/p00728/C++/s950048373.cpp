#include <iostream>
#include <vector>
using namespace std;
int main(){
  while(1){
    int n;
    cin >> n;
    if(n == 0)break;
    vector<int> array(n,0);
    int max_a = 0;
    int min_a = 10000;

    for(int i = 0;i < n;i++){
      int tmp;
      cin >> tmp;
      array[i] = tmp;
      max_a = max(max_a,tmp);
      min_a = min(min_a,tmp);

    }

    int sum = -1*(max_a + min_a);
    for(int i = 0; i < n;i++){
	sum += array[i];
    }
    cout << (int)(sum / (n-2)) << endl;
  }
  return 0;
}