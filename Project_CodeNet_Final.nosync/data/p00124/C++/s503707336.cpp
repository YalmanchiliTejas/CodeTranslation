#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef struct {
	int sum;
	char name[30];
} TEAM;

int main()
{
	int n;
	int win, lose, drow;
	bool flg = false;
	TEAM team[10], tmp;

	while (1){
		scanf("%d", &n);

		if (n == 0){
			break;
		}

		for (int i = 0; i < n; i++){
			scanf("%s %d %d %d", team[i].name, &win, &lose, &drow);
			team[i].sum = win * 3 + drow;
		}

		for (int i = 0; i < n; i++){
			for (int j = n - 1; j > i; j--){
				if (team[j].sum > team[j - 1].sum){
					tmp = team[j - 1];
					team[j - 1] = team[j];
					team[j] = tmp;
				}
			}
		}

		if (flg == true){
			cout << endl;
		}
		
		flg = true;

		for (int i = 0; i < n; i++){
			cout << team[i].name << "," << team[i].sum << endl;
		}
	}

	return (0);
}