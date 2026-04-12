#include <iostream>
using namespace std;

int main(){
	int N;
	char S[N];
	int K;
	char res[N];

	cin >> N;
	cin >> S;
	cin >> K;
	for (int i = 0; i < N; i++){
		if (S[i] == S[K-1]){
			res[i] = S[i];
		}else{
			res[i] = '*';
		}
	}
  	cout << res << endl;
}