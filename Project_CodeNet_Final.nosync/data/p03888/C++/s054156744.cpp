#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int main() {
	double a, b;
	cin >> a >> b;
	printf("%.10lf\n", (a * b) / (a + b));
}