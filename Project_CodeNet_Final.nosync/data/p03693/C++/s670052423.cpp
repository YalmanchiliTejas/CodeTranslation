#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<iomanip>



#define REP(i,n) for (int i = 0; (i) < (n); ++ (i))

using namespace std;
int a,b,c;

int main(){
  cin >> a >> b >> c;
  if((a*100+b*10+c)%4==0) cout << "YES" << endl;
  else cout << "NO" << endl;
  
  return 0;
}

