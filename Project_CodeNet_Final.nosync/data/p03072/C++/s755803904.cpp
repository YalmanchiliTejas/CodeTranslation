#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <math.h>
 
using namespace std;

int main(){
  int n;
  cin >> n;
  int ans=0;
  int h=0;
  
  for(int i=0;i<n;i++){
    int a;
    cin >>a;
    if(a>=h) ans++;
    h=max(h,a);
  }
  cout <<ans<< endl;
}