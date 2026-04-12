#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define ll long long
#define s second
#define f first

string s;
int a,b;

int main(){
  cin >> s;
  for(auto c:s){
    if(c=='A'){++a;}
    if(c=='B'){++b;}
  }
  if(a && b){cout << "Yes" << endl;}
  else{cout << "No" << endl;}
  return 0;
}
