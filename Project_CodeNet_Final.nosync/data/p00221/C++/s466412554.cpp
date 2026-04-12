#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

string itos(int n){
	stringstream ss; ss << n;
	return ss.str();
}
string get(int n){
	if(n % 15 == 0)return "FizzBuzz";
	if(n % 3 == 0)return "Fizz";	
	if(n % 5 == 0)return "Buzz";
	return itos(n);
}
int main(){
	int m,n;
	while(cin >> m >> n && m){
		vector<int> p(m);
		rep(i,m)p[i] = i;
		int pos = 0;
		rep(i,n){
			string t;
			cin >> t;
			if(p.size() == 1) continue;
			if(t == get(i+1) ) pos++;
			else p.erase(remove(p.begin(),p.end(),p[pos]),p.end());
			pos %= p.size();
		}
		rep(i,p.size())
			cout << p[i]+1 << (i == p.size()-1?"\n":" ");
	}
}