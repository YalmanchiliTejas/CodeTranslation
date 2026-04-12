#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
      cin >> s;
    int count=0;

 if(s.at(0)!=s.at(1))count++;
  else if(s.at(1)!=s.at(2))count++;
  
  if(count>=1)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
