#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	string S;
	cin >> S;
	for(int i = 0; i < S.length() - 1; i++){
		if(S[i] == 'A' && S[i + 1] == 'C'){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}
