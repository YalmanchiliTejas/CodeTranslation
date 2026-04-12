#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
  int n, hotel, ans = 1;
  cin >> n;
  vector<int> hotels;
  for(int i = 0; i < n; i++){
    cin >> hotel;
    sort(hotels.begin(), hotels.end());
    if(i != 0 && hotels[i-1] <= hotel) ans++;
    hotels.push_back(hotel);
  }
  cout << ans << endl;
  return 0;
}
