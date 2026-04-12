#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool fizzbuzz(int n, string s){
  if(n % 15 == 0) return (s == "FizzBuzz");
  if(n % 5 == 0) return (s == "Buzz");
  if(n % 3 == 0) return (s == "Fizz");
  /*for(int i = 0 ; i < s.size() ; i++){
    if(s[i] < '0' || s[i] > '9') return false;
    }*/
  return (atoi(s.c_str()) == n);
}

int main(){
  int m,n;
  string s;
  while(cin >> m >> n, m && n){
    vector<int> mem(m);
    int ii = 0;
    for(int i = 0 ; i < m ; i++) mem[i] = i+1;
    
    for(int i = 1 ; i <= n ; i++){
      //int p = i % m;
      cin >> s;
      if(mem.size() == 1) continue;
      else{
	if(fizzbuzz(i,s) == false){
	  mem.erase(remove(mem.begin(), mem.end(), mem[ii]), mem.end());
	  //mem[p] = 0;
	}
	else ii++;
       ii %= mem.size();
	//ii %= m;
      }
    }
    for(int i = 0 ; i < mem.size() ; i++){
      if(mem[i] != 0){
	cout << mem[i] << (i != mem.size()-1 ? " ":"");
      }
    }
    cout << endl;
  }
}