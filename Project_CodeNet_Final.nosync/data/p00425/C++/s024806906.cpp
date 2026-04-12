#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<functional>
#include<queue>
#include<stack>
#include<math.h>
#define INF 999999
#define EPS 1.0e-6

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

void rotation(int *d,int i,int j,int k,int l)
{
	int a = d[i];
	d[i] = d[j];
	d[j] = d[k];
	d[k] = d[l];
	d[l] = a;
}

int main()
{
	int n;
	while (1) {
		cin >> n;
		if (n == 0)break;
		
		int num = 1;
		int dice[6] = { 1,2,3,4,5,6 };
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			if (str == "North") {
				rotation(dice, 0, 1, 5, 4);
			}
			else if (str == "East") {
				rotation(dice, 0, 3, 5, 2);
			}
			else if (str == "West") {
				rotation(dice, 0, 2, 5, 3);
			}
			else if (str == "South") {
				rotation(dice, 0, 4, 5, 1);
			}
			else if (str == "Right") {
				rotation(dice, 1, 2, 4, 3);
			}
			else if (str == "Left") {
				rotation(dice, 1, 3, 4, 2);
			}
			num += dice[0];
		}
		cout << num << endl;
	}
	
	
	return 0;
}