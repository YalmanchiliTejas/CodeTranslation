#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long tnum;

#define loop(i, num) for(int i = 0; i < num; i++)

tnum* tnumAlloc(int num);
tnum getNumStdin();
tnum* getNumsStdin(int);
char* getCharsStdin(int maxlength);
string getStringStdin();
void printlnNums(int count, tnum* nums);
void printlnNum(tnum num);
void printString(string str);

#define min(a,b) (a <= b ? a : b)
#define max(a,b) (a >= n ? a : b)

/*void sort(T* start, T* end) (in <algorithm>)
example:
	int a[5] = {2, 1, 3, 5, 4};
	sort(a, a + 5);
	-> a: {1, 2, 3, 4, 5}
*/

int main() {
    char *s, *t;

    tnum n = getNumStdin();
    tnum *a = getNumsStdin(n);

    tnum sum1 = 0;
    tnum sum2 = 0;

    loop(i, n){
        sum2 += sum1 * a[i];
        sum2 %= 1000000007;
        sum1 += a[i];
        sum1 %= 1000000007;
    }

    printlnNum(sum2);

    return 0;
}



//have to be free()
tnum* tnumAlloc(int num) {
	return (tnum*)calloc(num,sizeof(tnum));
}

tnum getNumStdin() {
	tnum ret;
	scanf("%lld", &ret);

	return ret;
}

//have to be free()
tnum* getNumsStdin(int num) {
	tnum* buf;
	tnum* tmp;
	buf = tnumAlloc(num);
	for (int i = 0; i < num; i++) {
		scanf("%lld", &buf[i]);
	}

	return buf;
}

//have to be free()
char* getCharsStdin(int maxlength) {
	char* ret = (char*)malloc(maxlength+1);
	scanf("%s", ret);

	return ret;
}

//have to be free()
string getStringStdin() {
	string ret;
	cin >> ret;
	return ret;
}

void printlnNum(tnum num) {
	printf("%lld\n", num);
}

// can be used for debugging
void printlnNums(int count, tnum *nums) {
	loop(i, count) {
		printf("%lld", nums[i]);
		if (i != count - 1) printf(" ");
	}
	printf("\n");
}

void printString(string str) {
	cout << str;
}
