#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	if((a * 100 + b * 10 + c) % 4 == 0) cout << "YES";
	else cout << "NO";
}