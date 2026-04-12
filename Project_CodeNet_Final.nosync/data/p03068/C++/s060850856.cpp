#define _CRT_SECURE_NO_WARNINGS
#define MATH_PI 3.14159265358979323846264338327950288419716939
#include <iostream>
#include <string.h>
using namespace std;
/* 入力省略用汎用マクロ・クラス */
#define CLIP(ptr, min, max) {if((min)<=(max)){if(ptr<(min)){ptr=(min);}if(ptr>(max)){ptr=(max);}}}
#define max(a, b) a > b ? a : b;
#define min(a, b) a > b ? b : a;
#define Sin(deg) sin((deg)*MATH_PI/180)
#define Cos(deg) cos((deg)*MATH_PI/180)
#define Tan(deg) tan((deg)*MATH_PI/180)
#define Rad(deg) ((deg)*MATH_PI/180)
#define _for(num) for(int i=0 ; i<num ; ++i)
#define _forj(num) for(int j=0 ; j<num ; ++j)
#define _fork(num) for(int k=0 ; k<num ; ++k)
#define _forl(num) for(int l=0 ; l<num ; ++l)
#define _forn(num) for(int n=0 ; n<num ; ++n)
#define __for(param, num) for(int param=0 ; param<num ; ++param)
/* paiza用の入力データ処理クラス */
class myStr{FILE *fp;int ptr,EOL_flag;int LocalFileOpen();int LocalFileClose();int LocalRead();int GetNextData(int *s, int *e);public:myStr();~myStr();string buf;int bufsize;int StreamRead();int GetNextAsInt();char *GetNextAsChar();int isEOL();void Print(string *str);void Print(string &str);};
#ifdef DEBUGMODE
#include "LocalFunc.h"
#else
myStr::myStr(){}myStr::~myStr(){}
int myStr::StreamRead(){getline(cin, buf);ptr = 0;bufsize = buf.size();EOL_flag = 0;return 1;}
void wait(){}
#endif
int myStr::GetNextData(int *s, int *e){int i;for (i = ptr; i<bufsize; ++i) {if (buf[i] != ' ') {*s = i;break;}}if (i >= bufsize) {EOL_flag = 1;return 0;}for (; i<bufsize; ++i) {if (buf[i] == ' ') {break;}}*e = i - 1;ptr = i;return 1;}int myStr::GetNextAsInt(){int s, e;int ret = GetNextData(&s, &e);if (isEOL()) return 0;return atoi(&buf[s]);}char *myStr::GetNextAsChar(){int s, e;int ret = GetNextData(&s, &e);if (isEOL()) return NULL;char *chr;chr = new char[e - s + 2];int i;for (i = s; i <= e; ++i) {chr[i - s] = buf[i];}chr[i - s] = 0;return chr;}int myStr::isEOL(){return EOL_flag;}void myStr::Print(string *str){cout << str->c_str() << endl;}void myStr::Print(string &str){Print(&str);}
/* 便利系関数 */
#define SORT_ORDER_ASCENDING 1
#define SORT_ORDER_DESCENDING 2
int GetMax(int *arr, int arr_size, int if_equal_get_first_flag = 1, int *ret_index = NULL) {if (arr_size <= 0) abort();int mx = arr[0], index = 0;for (int n = 1; n<arr_size; ++n) {if (if_equal_get_first_flag && arr[n] >  mx ||!if_equal_get_first_flag && arr[n] >= mx) {index = n;mx = arr[n];}}if (*ret_index) *ret_index = index;return mx;}int GetMin(int *arr, int arr_size, int if_equal_get_first_flag = 1, int *ret_index = NULL) {if (arr_size <= 0) abort();int mn = arr[0], index = 0;for (int n = 1; n<arr_size; ++n) {if (if_equal_get_first_flag && arr[n] <  mn ||!if_equal_get_first_flag && arr[n] <= mn) {index = n;mn = arr[n];}}if (*ret_index) *ret_index = index;	return mn;}template<typename T> void bSort(T *arr, int arr_size, int order, int *rule1 = NULL, int *rule2 = NULL, int *rule3 = NULL, int *rule4 = NULL) {int swapped, flag;T tmp;while (true) {swapped = 0;for (int n = 0; n<arr_size - 1; ++n) {flag = 0;if (order == SORT_ORDER_ASCENDING) {if (!rule1) {if (arr[n] > arr[n + 1]) flag = 1;}else {if (rule1[n] > rule1[n + 1]) flag = 1;if (rule1[n] == rule1[n + 1] && rule2) {if (rule2[n] > rule2[n + 1]) flag = 1;if (rule2[n] == rule2[n + 1] && rule3) {if (rule3[n] > rule3[n + 1]) flag = 1;if (rule3[n] == rule3[n + 1] && rule4) {if (rule4[n] > rule4[n + 1]) flag = 1;}}}}}if (order == SORT_ORDER_DESCENDING) {if (!rule1) {if (arr[n] < arr[n + 1]) flag = 1;}else {if (rule1[n] < rule1[n + 1]) flag = 1;if (rule1[n] == rule1[n + 1] && rule2) {if (rule2[n] < rule2[n + 1]) flag = 1;if (rule2[n] == rule2[n + 1] && rule3) {if (rule3[n] < rule3[n + 1]) flag = 1;if (rule3[n] == rule3[n + 1] && rule4) {if (rule4[n] < rule4[n + 1]) flag = 1;}}}}}if (flag) {tmp = arr[n]; arr[n] = arr[n + 1]; arr[n + 1] = tmp;if (rule1) swap(rule1[n], rule1[n + 1]);if (rule2) swap(rule2[n], rule2[n + 1]);if (rule3) swap(rule3[n], rule3[n + 1]);if (rule4) swap(rule4[n], rule4[n + 1]);swapped = 1;}}if (!swapped) break;}}int Within(int px, int py, int x1, int y1, int x2, int y2, int allow_on_border = 1) {if (allow_on_border) {if (px >= x1 && px <= x2 && py >= y1 && py <= y2) return 1; else return 0;}else {if (px > x1 && px < x2 && py > y1 && py < y2) return 1; else return 0;}}
inline int separate(char *c1, char *c2, char *c3, char *c4) {unsigned int i;char *src, *s1, *s2;int flag;src = (char *)malloc(strlen(c1) + 1);s1 = (char *)malloc(strlen(c2) + 1);s2 = (char *)malloc(strlen(c2) + 1);strcpy(src, c1);strcpy(s2, c2);c3[0] = 0;c4[0] = 0;flag = 0;for (i = 0; i<strlen(src); i++) {strncpy(s1, src + i, strlen(s2));s1[strlen(s2)] = 0;if (strcmp(s1, s2) == 0) {strcpy(c3, src);c3[i] = 0;strcpy(c4, src + i + strlen(s2));flag = 1;break;}}free(s1);free(s2);if (flag) {free(src);return 1;}else {strcpy(c3, src);free(src);c4[0] = 0;return 0;}}
/****************************************************************/
/* 問題固有のクラス
/****************************************************************/

/****************************************************************/
/* メイン処理部
/****************************************************************/
int main(void) {

	int a, b, c;
	char *cbuf = NULL, cc[8192] = {0};

	myStr str;
	string s = "";

	str.StreamRead();
	a = str.GetNextAsInt();
	str.StreamRead();
	cbuf = str.GetNextAsChar();
	str.StreamRead();
	b = str.GetNextAsInt();

	_for(a){
		if(cbuf[i] == cbuf[b-1]){
			cc[i] = cbuf[i];
		}else{
			cc[i] = '*';
		}
	}

	cout << cc << endl;


	wait();

	return 0;
}

