#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

int comp(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}

int main() {
	char c;
	cin >> c;
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
		cout << "vowel" << endl;
	}else{
		cout << "consonant" << endl;
	}
}