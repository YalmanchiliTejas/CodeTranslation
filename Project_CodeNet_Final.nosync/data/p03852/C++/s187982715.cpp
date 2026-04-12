#define _USE_MATH_DEFINES
#include<stdio.h>
#include<string>
#include<iostream>
#include<cctype>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include <algorithm>
#include<math.h>
#include<set>
#include<map>
#include<iomanip>

//#include<bits/stdc++.h>


using namespace std;


int main() {
	
	char a;
	cin >> a;
	if (a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o')cout << "vowel" << endl;
	else cout << "consonant" << endl;
	return 0;

}


