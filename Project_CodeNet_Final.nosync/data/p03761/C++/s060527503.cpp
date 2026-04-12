#include<iostream>
#include<cstring>

using namespace std;

int main(){
	int n;
	char alphabet[27];
	int alphabetnum[26];
	char buff[51];
	strncpy(alphabet, "abcdefghijklmnopqrstuvwxyz", 27);
	for(int i = 0; i < 26; i++){
		alphabetnum[i] = 100;
	}
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> buff;
		int buffnum[26] = {0};
		for(int j = 0; j < 50; j++){
			if(buff[j] == '\0'){
				break;
			}
			for(int k = 0; k < 26; k++){
				if(buff[j] == alphabet[k]){
					buffnum[k]++;
					break;
				}
			}
		}
		for(int j = 0; j < 26; j++){
			if(buffnum[j] < alphabetnum[j]){
				alphabetnum[j] = buffnum[j];
			}
		}
	}
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < alphabetnum[i]; j++){
			cout << alphabet[i];
		}
	}
	cout << endl;
	return 0;
}