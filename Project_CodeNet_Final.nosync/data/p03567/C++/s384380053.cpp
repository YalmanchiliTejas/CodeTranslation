#include <stdio.h>
#include <iostream>

using namespace std;

int main(void){
	char s[6];

	scanf("%s", s);

	int i = 0;
	while (s[i+1] != '\0'){
		if (s[i] == 'A' && s[i+1] == 'C'){
			cout << "Yes" << endl;
			return 0;
		}
		i++;
	}

	cout << "No" << endl;

	return 0;

}