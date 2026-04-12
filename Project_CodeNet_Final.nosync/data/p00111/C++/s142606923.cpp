#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int main(){

	char base[205],middle[2000],result[2000];
	int p;

	while(fgets(base,205,stdin) != 0){

		p = 0;

		for(int i = 0; base[i] != '\0'; i++){
			switch(base[i]){
			case ' ':
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '0';
				break;
			case '\'':
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '0';
				break;
			case ',':
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '0';
				break;
			case '-':
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '1';
				break;
			case '.':
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '1';
				break;
			case '?':
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '1';
				break;
			case 'A':
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '0';
				break;
			case 'B':
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '1';
				break;
			case 'C':
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '0';
				break;
			case 'D':
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '1';
				break;
			case 'E':
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '0';
				break;
			case 'F':
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '1';
				break;
			case 'G':
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '0';
				break;
			case 'H':
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '1';
				break;
			case 'I':
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '0';
				break;
			case 'J':
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '1';
				break;
			case 'K':
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '0';
				break;
			case 'L':
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '1';
				break;
			case 'M':
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '0';
				break;
			case 'N':
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '1';
				break;
			case 'O':
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '0';
				break;
			case 'P':
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '1';
				break;
			case 'Q':
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '0';
				break;
			case 'R':
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '1';
				break;
			case 'S':
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '0';
				break;
			case 'T':
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '1';
				break;
			case 'U':
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '0';
				break;
			case 'V':
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '1';
				break;
			case 'W':
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '0';
				break;
			case 'X':
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '1';
				break;
			case 'Y':
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '0';
				break;
			case 'Z':
				middle[p++] = '1';
				middle[p++] = '1';
				middle[p++] = '0';
				middle[p++] = '0';
				middle[p++] = '1';
				break;
			}
		}
		middle[p] = '\0';

		p = 0;

		for(int i = 0; middle[i] != '\0';){
			if(middle[i+2] == '\0'){
				break;
			}else if(middle[i] == '1' && middle[i+1] == '0' && middle[i+2] == '1'){
				result[p++] = ' ';
				i += 3;
			}else if(middle[i] == '1' && middle[i+1] == '1' && middle[i+2] == '0'){
				result[p++] = 'E';
				i += 3;
			}else if(middle[i] == '1' && middle[i+1] == '1' && middle[i+2] == '1'){
				result[p++] = 'P';
				i += 3;
			}else if(middle[i+3] == '\0'){
				break;
			}else if(middle[i] == '0' && middle[i+1] == '1' && middle[i+2] == '0' && middle[i+3] == '1'){
				result[p++] = 'C';
				i += 4;
			}else if(middle[i] == '0' && middle[i+1] == '0' && middle[i+2] == '0' && middle[i+3] == '1'){
				result[p++] = 'D';
				i += 4;
			}else if(middle[i] == '0' && middle[i+1] == '1' && middle[i+2] == '1' && middle[i+3] == '1'){
				result[p++] = 'I';
				i += 4;
			}else if(middle[i] == '0' && middle[i+1] == '1' && middle[i+2] == '1' && middle[i+3] == '0'){
				result[p++] = 'K';
				i += 4;
			}else if(middle[i] == '1' && middle[i+1] == '0' && middle[i+2] == '0' && middle[i+3] == '0'){
				result[p++] = 'R';
				i += 4;
			}else if(middle[i+4] == '\0'){
				break;
			}else if(middle[i] == '0' && middle[i+1] == '1' && middle[i+2] == '0' && middle[i+3] == '0' && middle[i+4] == '1'){
				result[p++] = 'F';
				i += 5;
			}else if(middle[i] == '0' && middle[i+1] == '0' && middle[i+2] == '1' && middle[i+3] == '0' && middle[i+4] == '0'){
				result[p++] = 'L';
				i += 5;
			}else if(middle[i] == '0' && middle[i+1] == '0' && middle[i+2] == '1' && middle[i+3] == '0' && middle[i+4] == '1'){
				result[p++] = 'O';
				i += 5;
			}else if(middle[i] == '0' && middle[i+1] == '0' && middle[i+2] == '1' && middle[i+3] == '1' && middle[i+4] == '0'){
				result[p++] = 'S';
				i += 5;
			}else if(middle[i] == '0' && middle[i+1] == '0' && middle[i+2] == '1' && middle[i+3] == '1' && middle[i+4] == '1'){
				result[p++] = 'T';
				i += 5;
			}else if(middle[i+5] == '\0'){
				break;
			}else if(middle[i] == '0' && middle[i+1] == '0' && middle[i+2] == '0' && middle[i+3] == '0' && middle[i+4] == '0' && middle[i+5] == '0'){
				result[p++] = '\'';
				i += 6;
			}else if(middle[i] == '0' && middle[i+1] == '0' && middle[i+2] == '0' && middle[i+3] == '0' && middle[i+4] == '1' && middle[i+5] == '1'){
				result[p++] = ',';
				i += 6;
			}else if(middle[i] == '0' && middle[i+1] == '1' && middle[i+2] == '0' && middle[i+3] == '0' && middle[i+4] == '0' && middle[i+5] == '1'){
				result[p++] = '.';
				i += 6;
			}else if(middle[i] == '0' && middle[i+1] == '0' && middle[i+2] == '0' && middle[i+3] == '0' && middle[i+4] == '0' && middle[i+5] == '1'){
				result[p++] = '?';
				i += 6;
			}else if(middle[i] == '1' && middle[i+1] == '0' && middle[i+2] == '0' && middle[i+3] == '1' && middle[i+4] == '0' && middle[i+5] == '1'){
				result[p++] = 'A';
				i += 6;
			}else if(middle[i] == '0' && middle[i+1] == '1' && middle[i+2] == '0' && middle[i+3] == '0' && middle[i+4] == '0' && middle[i+5] == '0'){
				result[p++] = 'H';
				i += 6;
			}else if(middle[i] == '0' && middle[i+1] == '0' && middle[i+2] == '0' && middle[i+3] == '0' && middle[i+4] == '1' && middle[i+5] == '0'){
				result[p++] = 'W';
				i += 6;
			}else if(middle[i+7] == '\0'){
				break;
			}else if(middle[i] == '1' && middle[i+1] == '0' && middle[i+2] == '0' && middle[i+3] == '1' && middle[i+4] == '0' && middle[i+5] == '0' && middle[i+6] == '0' && middle[i+7] == '1'){
				result[p++] = '-';
				i += 8;
			}else if(middle[i] == '1' && middle[i+1] == '0' && middle[i+2] == '0' && middle[i+3] == '1' && middle[i+4] == '1' && middle[i+5] == '0' && middle[i+6] == '1' && middle[i+7] == '0'){
				result[p++] = 'B';
				i += 8;
			}else if(middle[i] == '1' && middle[i+1] == '0' && middle[i+2] == '0' && middle[i+3] == '1' && middle[i+4] == '1' && middle[i+5] == '0' && middle[i+6] == '1' && middle[i+7] == '1'){
				result[p++] = 'G';
				i += 8;
			}else if(middle[i] == '1' && middle[i+1] == '0' && middle[i+2] == '0' && middle[i+3] == '1' && middle[i+4] == '1' && middle[i+5] == '0' && middle[i+6] == '0' && middle[i+7] == '0'){
				result[p++] = 'J';
				i += 8;
			}else if(middle[i] == '1' && middle[i+1] == '0' && middle[i+2] == '0' && middle[i+3] == '1' && middle[i+4] == '1' && middle[i+5] == '0' && middle[i+6] == '0' && middle[i+7] == '1'){
				result[p++] = 'M';
				i += 8;
			}else if(middle[i] == '1' && middle[i+1] == '0' && middle[i+2] == '0' && middle[i+3] == '1' && middle[i+4] == '1' && middle[i+5] == '1' && middle[i+6] == '1' && middle[i+7] == '0'){
				result[p++] = 'N';
				i += 8;
			}else if(middle[i] == '1' && middle[i+1] == '0' && middle[i+2] == '0' && middle[i+3] == '1' && middle[i+4] == '1' && middle[i+5] == '1' && middle[i+6] == '1' && middle[i+7] == '1'){
				result[p++] = 'Q';
				i += 8;
			}else if(middle[i] == '1' && middle[i+1] == '0' && middle[i+2] == '0' && middle[i+3] == '1' && middle[i+4] == '1' && middle[i+5] == '1' && middle[i+6] == '0' && middle[i+7] == '0'){
				result[p++] = 'U';
				i += 8;
			}else if(middle[i] == '1' && middle[i+1] == '0' && middle[i+2] == '0' && middle[i+3] == '1' && middle[i+4] == '1' && middle[i+5] == '1' && middle[i+6] == '0' && middle[i+7] == '1'){
				result[p++] = 'V';
				i += 8;
			}else if(middle[i] == '1' && middle[i+1] == '0' && middle[i+2] == '0' && middle[i+3] == '1' && middle[i+4] == '0' && middle[i+5] == '0' && middle[i+6] == '1' && middle[i+7] == '0'){
				result[p++] = 'X';
				i += 8;
			}else if(middle[i] == '1' && middle[i+1] == '0' && middle[i+2] == '0' && middle[i+3] == '1' && middle[i+4] == '0' && middle[i+5] == '0' && middle[i+6] == '1' && middle[i+7] == '1'){
				result[p++] = 'Y';
				i += 8;
			}else if(middle[i] == '1' && middle[i+1] == '0' && middle[i+2] == '0' && middle[i+3] == '1' && middle[i+4] == '0' && middle[i+5] == '0' && middle[i+6] == '0' && middle[i+7] == '0'){
				result[p++] = 'Z';
				i += 8;
			}else{
				break;
			}
		}

		result[p] = '\0';
		printf("%s\n",result);

	}

	return 0;
}