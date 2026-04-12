#include <bits/stdc++.h>
typedef long long int lint;

#define PI acos(-1)
#define INF64 1LL << 60
#define INF32 1 << 29
#define LIMIT(d_in, d_min, d_max) max(d_min, min(d_max, d_in))
#define all(a) (a).begin(), (a).end()
#define INV ((long long int)1000000007)

using namespace std;
lint CountP(lint current, lint N, int X, vector<lint> BP, vector<lint> P)
{
	if (X < 0)
		return current + 1;
	//cout << N << " " << X << " " << BP[X] << " " << P[X] << endl;

	if (N == 1)
		return current;
	else if (N <= 1 + BP[X])
		return CountP(current, N - 1, X - 1, BP, P);
	else if (N <= 1 + BP[X] + 1)
		return current + 1 + P[X];
	else if (N <= 1 + BP[X] + 1 + BP[X])
		return CountP(current + 1 + P[X], N - 1 - BP[X] - 1, X - 1, BP, P);
	else
		return current + P[X] * 2 + 1;
}
void execute()
{
	lint N;
	int X;
	cin >> X >> N;

	vector<lint> BP(X + 1);
	vector<lint> P(X + 1);
	BP[0] = 1;
	P[0] = 1;
	for (int i = 0; i < X; i++)
	{
		BP[i + 1] = BP[i] * 2 + 3;
		P[i + 1] = P[i] * 2 + 1;
	}
	cout << CountP(0, N, X - 1, BP, P) << endl;
	return;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	execute();

	int stop;
	cin >> stop;

	return 0;
}