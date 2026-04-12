#include <iostream>
#include <string>
using namespace std;
int main(){
string str;
int a,b,c;
cin >> a >> b >> c;
if(((c += a * 100 + b * 10) % 4) == 0)
	cout << "YES" << endl;
else
	cout << "NO" << endl;
}