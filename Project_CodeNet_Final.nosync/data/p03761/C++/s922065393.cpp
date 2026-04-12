#include<iostream>
#include<string>
#include<typeinfo>
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
typedef long long int ll;
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> ascii(128,0);
	string s;
	cin >> s;
	for(int i=0; i<s.size(); i++){
		ascii.at(s.at(i))++;
	}
	for(int i=0; i<n-1; i++){
		cin >> s;
		vector<int> tmpascii(128,0);
		for(int j=0; j<s.size(); j++){
			tmpascii.at(s.at(j))++;
		}
		for(int j='a'; j<='z'; j++){
			if(tmpascii.at(j)<ascii.at(j)){
				ascii.at(j)=tmpascii.at(j);
			}
		}
	}

	for(int i='a'; i<='z'; i++){
		for(int j=0; j<ascii.at(i); j++){
			char c=i;
			cout << c;
		}
	}
	cout << endl;
	return 0;
}