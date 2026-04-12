#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<string> input(int height)
{
	int i;
	vector<string> inp(height);

	for (i = 0; i < height; i++) {
		cin >> inp[i];
	}

	return inp;
}

int main(int argc, char *argv[])
{
	int i, j;
	int h, w;
	cin >> h >> w;
	vector<string> org;
	string::iterator it;
	org = input(h);
	int flags[w];
	string white(w, '.');
	for (i = 0; i < w; i++) 
		flags[i] = 0;
	
	auto result = remove_if(org.begin(), org.end(),
							[&white](string s) { return s == white; });

	org.erase(result, org.end());
	org.shrink_to_fit();	

	for (i = 0; i < w; i++) {
		if ((org.front())[i] == '.') {
			for (j = 0; j < org.size(); j++) {
				if ((org[j])[i] != '.')
					break;
			}
			if (j == org.size()) 
				flags[i] = 1;
		}
	}
	
	for (i = w - 1; i >= 0; i--) {
		if (flags[i] == 1) {
			for (j = 0; j < org.size(); j++) 
				org[j].erase(org[j].begin() + i);
		}
	}
	
	for (i = 0; i < org.size(); i++) 
		cout << org[i] << endl;

	return 0;
}
