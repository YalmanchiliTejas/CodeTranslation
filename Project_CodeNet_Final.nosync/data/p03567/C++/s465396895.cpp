#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
template<typename T>
void get(T& t){cin >> t;}
int main(void){
	string s;
	get(s);
	if(s.find("AC") < s.size())cout << "Yes"<<endl;
	else cout << "No"<<endl;return 0;
}
