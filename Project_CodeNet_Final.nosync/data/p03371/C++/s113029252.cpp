#include <stdio.h>

int main() {
	int a, b, c, x, y;
	scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
	int sum = 0;

	int z;//xとyの共通部分
	if (x < y) z = x;
	else z = y;

	//共通部分までの最適解を見つける
	if ((a + b) > (c * 2)) {//c*2の方がお得
		sum += z * 2 * c;
	}
	else {//単純に買うのがお得
		sum += a*z + b*z;
	}

	if (x == z) {//yが残っている場合
		if (c * 2 < b) {//cで買う方がお得
			sum += c * 2 * (y - z);
		}
		else {//単純がお得
			sum += b*(y - z);
		}
	}
	else {//xが残っている場合
			if (c * 2 < a) {//cで買う方がお得
				sum += c * 2 * (x - z);
			}
			else {//単純がお得
				sum += a*(x - z);
			}
	}
	printf("%d\n", sum);
}