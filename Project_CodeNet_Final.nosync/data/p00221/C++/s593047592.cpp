#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

string table[10001];

string itos(int n){
	stringstream ss;
	ss << n;
	return ss.str();
}

int main(){
	for(int i = 1 ; i <= 10000 ; i++){
		if(i%15==0){
			table[i] = "FizzBuzz";
		}else if(i%3==0){
			table[i] = "Fizz";
		}else if(i%5==0){
			table[i] = "Buzz";
		}else{
			table[i] = itos(i);
		}
	}
	int n,m;
	while(cin >> n >> m && n){
		vector<int> v(n);
		for(int i = 0 ; i < n ; i++) v[i] = i;
		int x = 0;
		for(int z = 1 ; z <= m ; z++){
			string s; cin >> s;
			if(v.size()==1) continue;
			if(s != table[z]){
				v.erase(remove(v.begin(),v.end(),v[x]),v.end());
			}else{
				x++;
			}
			x %= v.size();
		}
		for(int i = 0 ; i < v.size() ; i++)
			cout << v[i]+1 << (v.size()-1==i?"\n":" ");
	}
}