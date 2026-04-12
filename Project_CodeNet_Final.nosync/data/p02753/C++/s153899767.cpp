#define rep(i,n) for (int i=0;i<n;i++)
#include <bits/stdc++.h>
using namespace std;

int main(){
  int c;
	string S;
  cin >> S;
  
  rep(i,3){
    if(S.at(i)=='A')
      c++;
  }
  if(c==3 || c==0)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
    
}


