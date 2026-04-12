#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <map>

#define ST_ARR_LEN(array) (sizeof(array)/sizeof(*array))

using namespace std;

using ll = long long;

typedef stack<int> IntStack;
typedef queue<int> IntQueue;
typedef vector<int> IntVector;
typedef list<int> IntList;

typedef struct S{
  int a;
  int b;
} Object;

int main(){
  int N, M;
  cin >> N >> M;
  
  string ans;
  if(N == M){
  	ans = "Yes";
  }else{
    ans = "No";
  }
  
  cout << ans << endl;
}