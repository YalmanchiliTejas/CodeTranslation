#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	double a, b; cin >> a >> b;
	printf("%.9f\n", 1 / (1 / a + 1 / b));
}