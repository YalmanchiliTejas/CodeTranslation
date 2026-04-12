#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <stack>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <climits>
#include <list>
#include <time.h>
#include <unordered_map>
#include <bitset>
#include <exception>

using namespace std;


int main(){
  int n;
  cin >> n;
  int arr[n];
  int count = 1;
  int currMax;
  cin >> currMax;
  int temp;
  
  for(int i = 0; i < n-1; i++){
    cin >> temp;
    if (temp >= currMax){
      count++;
      currMax = temp;
    }
  }
  cout << count <<endl;
  
  
  
}
