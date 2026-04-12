#include <algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>

#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

using namespace std;
int main(){
  int age;
  cin >> age;
  if(age == 3||age == 5||age == 7){
	cout << "YES\n";
  }
  else{
	cout << "NO\n";
  }
  return 0;
}
