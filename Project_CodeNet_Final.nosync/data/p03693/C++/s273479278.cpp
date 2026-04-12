#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
using namespace std;

#define ll int64_t
const long MOD = 1e9 + 7;


int main()
{
 int a,b,c;
  cin >> a >> b >> c;
  if ( (b%2*10 +c ) %4 ==0){
    cout <<"YES";
  }else{
	cout <<"NO";
  }
}