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
char a;

int main(){
  cin >> a;
  if(a=='a'||a=='i'||a=='u'||a=='e'||a=='o') cout << "vowel" << endl;
  else cout << "consonant" << endl;
  
  return 0;
}

