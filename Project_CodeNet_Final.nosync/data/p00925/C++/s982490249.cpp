#include <bits/stdc++.h>
using namespace std;

string str;
int ans;

bool A()
{
	stringstream ss(str);
	
	vector<int> num;
	vector<char> sign;
	
	int t = 0;
	while (!ss.eof()){
		if (!t){
			int s;
			ss >> s;
			
			if (sign.size() && sign.back() == '*'){
				num[num.size() - 1] *= s;
				sign.pop_back();
			}
			else num.push_back(s);
		}
		else {
			char s;
			ss >> s;
			sign.push_back(s);
		}
		t ^= 1;
	}
	
	int res = 0;
	for (int i = 0; i < num.size(); i++){
		res += num[i];
	}
	
	return res == ans;
}

bool B()
{
	stringstream ss(str);
	
	vector<int> num;
	vector<char> sign;
	
	int t = 0;
	while (!ss.eof()){
		if (!t){
			int s;
			ss >> s;
			
			if (sign.size()){
				if (sign.back() == '*') num[num.size() - 1] *= s;
				if (sign.back() == '+') num[num.size() - 1] += s;
				sign.pop_back();
			}
			else num.push_back(s);
		}
		else {
			char s;
			ss >> s;
			sign.push_back(s);
		}
		t ^= 1;
	}
	
	return num.back() == ans;
}

int main()
{
	cin >> str >> ans;
	const char* s = "ILMU";
	int res = (A() << 1) | B();
	printf("%c\n", s[res]);
}