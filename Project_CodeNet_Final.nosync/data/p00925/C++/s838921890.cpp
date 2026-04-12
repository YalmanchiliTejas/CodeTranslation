#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	string f; cin >> f;
	int a; cin >> a;
	int n = f.size() / 2;
	int l = f[0] - '0';
	for(int i = 0; i < n; i++){
		if(f[i*2+1] == '+'){
			l += f[i*2+2] - '0';
		}else{
			l *= f[i*2+2] - '0';
		}
	}
	vector<int> v;
	v.push_back(f[0] - '0');
	for(int i = 0; i < n; i++){
		if(f[i*2+1] == '+'){
			v.push_back(f[i*2+2] - '0');
		}else{
			v[v.size() - 1] *= f[i*2+2] - '0';
		}	
	}
	int m = 0;
	for(auto i: v) m += i;
	if(a==m && a==l) cout << 'U' << endl;
	if(a!=m && a==l) cout << 'L' << endl;
	if(a==m && a!=l) cout << 'M' << endl;
	if(a!=m && a!=l) cout << 'I' << endl;
	return 0;
}