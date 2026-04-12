#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int chair, width, pad, people;
  cin >> chair >> width >> pad;

  chair = chair - pad;
  people = floor(chair / (width + pad));

  cout << people << endl;
}
