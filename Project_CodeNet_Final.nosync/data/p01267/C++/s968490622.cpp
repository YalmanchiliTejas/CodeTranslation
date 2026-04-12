#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int i, N, A, B, C, X, count;

	while(1){
		count = 0;
		cin >> N >> A >> B >> C >> X;
		if(N == 0 && A == 0 && B == 0 && C == 0 && X == 0){
			break;
		}

		vector<int> rail(N);
		for(i = 0; i < N; i++){
			cin >> rail[i];
		}
		
		i = 0;
		while(1){
			if(rail[i] == X){
				rail[i] = -1;
				i += 1;
			}
			if(i == N){
				cout << count << endl;
				break;
			}
			count += 1;
			X = ( A * X + B ) % C;
			if(count == 10001){
				cout << -1 << endl;
				break;
			}
		}
	}
	return 0;
}