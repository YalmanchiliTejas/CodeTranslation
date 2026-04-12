#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int s1, s2;
	
	while (cin >> s1 >> s2, s1 || s2){
		
		int max = s1 + s2, max_n = 0 + 'A';
		
		for (int i = 1; i < 5; i++){
			cin >> s1 >> s2;
			if (max < s1 + s2){
				max = s1 + s2;
				max_n = i + 'A';
			}
		}
		
		printf("%c %d\n", max_n, max);
	}
	return (0);
}