#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>


using namespace std;



int main(){
  int a,b,c;
  std::cin >> a>>b>>c;
  std::cout << (a-c)/(b+c) << '\n';
}
