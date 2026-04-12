#include<functional>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<string>
#include<math.h>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
int main(){
  int r,g,b;
  cin>>r>>g>>b;
  int a=g*10+b;
  cout<<((a%4==0)?"YES":"NO")<<endl;
  return 0;
}
      
