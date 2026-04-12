#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int alph[26];
	for(int i = 0; i < 7; i++){
		alph[i] = 0;
	}
	for(int i = 7; i < 16; i++){
		alph[i] = 1;
	}
	for(int i = 16; i < 20; i++){
		alph[i] = 0;
	}
	alph[20] = 1;
	alph[21] = 0;
	alph[22] = 0;
	alph[23] = 0;
	alph[24] = 1;
	alph[25] = 0;
	int cnt=0, j=0, k=-1;
	while(1){
		j = getchar();
		if(j == '#'){
			break;
		} else if(j == '\n'){
			cout << cnt << endl;
			cnt = 0;
			j = 0;
			k = -1;
		} else {
			int l;
			l = j - 'a';
			if(k == -1){
				k = alph[l];
			}
			else if(k != alph[l]){
				cnt++;
				k = alph[l];
			}
		} 
	}
	return 0;
}