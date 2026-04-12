#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <cmath>
#include <map>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]){

  int N;
  cin >> N;
  int H = 0;
  int count = 0;
  for(int i = 0; i < N; i++){
    int tmp = 0;
    cin >> tmp;
    if(H <= tmp){
        count++;
        H = tmp;
    }
  }


  cout << count << endl;

  return 0;
}
