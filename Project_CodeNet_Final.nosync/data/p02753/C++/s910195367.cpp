#include<bits/stdc++.h>
using namespace std;

int a[2];
int main(){
  string str;
  cin >> str;
  for(auto &c:str)
  	a[c-'A']++;
  if(a[0] and a[1])
    	cout << "Yes\n";
  else
    	cout << "No\n";
}