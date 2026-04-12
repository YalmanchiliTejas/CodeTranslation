#include <iostream>
#include <string>

using namespace std;

void A_Station_and_Bus(void) {

	string S;

	cin >> S;

	cout << ((S[0] == S[1] && S[0] == S[2]) ? "No" : "Yes");

	return;
}

void B_Count_Balls(void) {

	long n;
	int a, b;
	long count = 0;

	cin >> n >> a >> b;

	count = (n - (n % (a + b))) / (a + b);

	if (n % (a + b) <= a) {

		cout << n % (a + b) + count * a;
	}
	else {

		cout << a + count * a;
	}

	return;
}

void C_Tax_Increase(void) {

	int a, b;

	int pa[1000] = { -1 };
	int pb[1000] = { -1 };

	int flag = 0;

	int re = 0;

	cin >> a >> b;

	for (int loop = 1; loop < 1400; loop++) {

		if ((int)(loop * 0.08) == a && flag < 1000) {
			pa[flag] = loop;
			flag++;
		}
	}

	flag = 0;
	for (int loop = 1; loop < 1400; loop++) {

		if ((int)(loop * 0.1) == b && flag < 1000) {
			pb[flag] = loop;
			flag++;
		}
	}

	for (int xloop = 0; xloop < 1000; xloop++) {

		for (int yloop = 0; yloop < 1000; yloop++) {

			if (pa[xloop] != -1 && pa[xloop] == pb[yloop]) {

				re = pa[xloop];
			}
		}
	}

	for (int xloop = 0; xloop < 1000; xloop++) {

		for (int yloop = 0; yloop < 1000; yloop++) {

			if (pa[yloop] != -1 && pa[yloop] == pb[xloop]) {

				if (re > pa[yloop]) re = pa[yloop];
			}
		}
	}

	if (re > 0) {

		cout << re << flush;
	}
	else {

		cout << -1 << flush;
	}

	return;
}

void D_String_Formation(void) {

	string S;
	int Q;

	cin >> S;
	cin >> Q;

	int T;
	int F;
	char C;

	int max = 0;
	char sBuff;

	int loop1 = 0;
	int loop2 = 0;

	for (loop1 = 0; loop1 < Q; loop1++) {

		cin >> T;

		if (T == 1) {

			max = (int)(S.size() * 0.5);

			for (loop2 = 0; loop2 < max; loop2++) {

				sBuff = S[loop2];
				S[loop2] = S[S.size() - loop2 - 1];
				S[S.size() - loop2 - 1] = sBuff;
			}
		}
		else {

			cin >> F >> C;

			if (F == 1) {

				S = C + S;
			}
			else {

				S = S + C;
			}
		}
	}

	cout << S;

	return;
}

int main(void) {

	A_Station_and_Bus();
	//B_Count_Balls();
	//C_Tax_Increase();
	//D_String_Formation();

	return 0;
}
