#include <iostream>
#include <string>
#include<cstring>
#include<stdio.h>
using namespace std;
const int MAX = 1e5 + 5;
int Xi[MAX]; int Li[MAX];int yes[MAX] ;
int cmp(const void *a, const void *b)
{
	return *(char *)a - *(int *)b;
}
int  main() {
	int N = 0, M = 0;
	cin >> N >> M; 
	if (M >= N)cout << "Yes"; else cout << "No";



	return 0;

}