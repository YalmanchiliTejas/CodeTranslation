#include <bits/stdc++.h>

#define o(output) cout << output << endl

using namespace std;

string s;
int a,b,c,d,e;
char A,B;
priority_queue<int,vector<int>,greater<int> >small;

int main(){
  cin >> a >> A >>B;
  b = A-'0';
  c = B-'0';
  if((10*b+c)%4==0)o("YES");
  else o("NO");
}