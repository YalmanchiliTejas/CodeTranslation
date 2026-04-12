#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;



int main(){
  ios_base::sync_with_stdio(false);

  int n;

  cin >> n;

  if(n == 7 || n == 5 || n == 3){
    cout <<  "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}

