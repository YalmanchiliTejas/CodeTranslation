//tenka1_2019_b.cpp
//Tue Apr 30 16:41:59 2019

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int k;
	cin >> k;

	char substletter = s[k-1];

	for (int i=0;i<n;i++){
		if (s[i] != substletter){
			cout << "*";
		}else {
			cout << s[i];
		}
	}

	printf("\n");
//	cout << s << endl;
//	printf("%.4f\n",ans);
}