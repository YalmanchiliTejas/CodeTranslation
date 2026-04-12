#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <set>
#include <map>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define for_p(i, a, b) for(int i = a; i < b; i++)
#define for_m(i, a, b) for(int i = a - 1; i >= b; i--)

//a = s1.size();
//vector<string> s1;
//string s2 = accumulate( s1.begin(), s1.end(), string() );

using namespace std;

int main()
{
  int a = 0 , b = 0, c = 0, d = 0, e = 0, f = 0;
  int i = 0, j = 0;
  double d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0;
  int a1[256], a2[512], a3[1024];
  char s1[200000], s2[200000], s3[200000];
  
  cin >> a;
  
  for(i = 0; i < a; i++){
    cin >> a1[i];
  }
  
  b++;
  
  for(i = 1; i < a; i++){
    for(j = 0; j < i; j++){
      if(a1[j] > a1[i]){
        c++;
      }
    }
    if(c == 0){
      b++;
    }
    c = 0;
  }
  cout << b << endl;
} 
  




