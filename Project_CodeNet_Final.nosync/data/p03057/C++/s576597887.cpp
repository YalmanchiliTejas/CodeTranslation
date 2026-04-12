#include <stdio.h>
#include <vector>
using namespace std;

int N, M; char S[200200];

const long long mod = 1000000007;
long long D[200200], V[200200];

int main()
{
	scanf ("%d %d %s", &N, &M, S);
	if (S[0] == 'B'){
		for (int i = 0; i < M; i++){
			if (S[i] == 'R') S[i] = 'B';
			else S[i] = 'R';
		}
	}

	vector<int> len;
	for (int i = 1, l = -1; i < M; i++){
		if (S[i-1] == 'R' && S[i] == 'B'){
			int u = i - l - 1;
			len.push_back(u);
		}
		if (S[i] == 'B') l = i;
	}

	if (len.empty()){
		if (N == 2){
			printf ("3\n");
			return 0;
		}
		D[0] = 1;
		D[1] = 2;
		for (int i = 2; i <= N; i++) D[i] = (D[i - 1] + D[i - 2]) % mod;
		printf ("%lld\n", (D[N - 1] + D[N - 3]) % mod);
		return 0;
	}
	if (N == 2){
		printf ("2\n");
		return 0;
	}
	if (N % 2){
		printf ("0\n");
		return 0;
	}

	int lim = len[0];
	if (lim % 2 == 0) lim++;
	for (int i = 1; i < len.size(); i++){
		if (len[i] % 2){
			if (lim > len[i])
				lim = len[i];
		}
	}

	D[0] = V[0] = 1;
	for (int i = 1; i <= N; i++){
		if (i <= lim + 1) D[i] = i - 1;
		if (i >= 2) D[i] = (D[i] + V[i - 2]) % mod;
		if (i >= lim + 3) D[i] = (D[i] + mod - V[i - (lim + 3)]) % mod;
		V[i] = D[i];
		if (i >= 2) V[i] = (V[i] + V[i - 2]) % mod;
	}
	printf ("%lld\n", D[N]);

	return 0;
}
