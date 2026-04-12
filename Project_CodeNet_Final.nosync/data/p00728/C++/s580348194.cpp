#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
  int n;
  int point[100], average;
  
  while(1){
    average = 0;
    cin >> n;
    if(n == 0) break;

    for(int i = 0 ; i < n ; i++){
      cin >> point[i];
    }
    sort(point, point + n);
    for(int i = 1 ; i < n - 1 ; i++){
      average += point[i];
    }
    average /= (n-2);
    cout << average << endl;
  }
  return 0;
}