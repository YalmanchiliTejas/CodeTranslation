#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <math.h>
#include <list>
using namespace std;

int main()
{
  int N,K; cin >> N;
  string s; cin >> s;
  cin >> K;
  
  for(int i = 0; i < N; i++){
    if(s.at(i) == s.at(K-1)) cout << s.at(i);
    else cout << '*';
  }
  
  cout << endl;
}