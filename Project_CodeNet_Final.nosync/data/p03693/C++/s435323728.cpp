#include <stdio.h>
#include <vector>
#include <memory.h>
#include <iostream>
#include <map>
#include <algorithm>
  
// Shabdan Batyrkulov
  
using namespace std;
  
#define pb push_back
#define fr first
#define sc second
#define mk make_pair
#define ll long long
#define ld long double
#define vi vector <int>
#define pii pair <int, int>
#define OK puts("OK");                                                                           
                                                                                                
const int N = (int)1e5 + 7;                                                                 
const int inf = (int)1e9 + 7;
const int MAX = (int)1e2 + 7;


int main () {
	int r, g, b;
	scanf("%d %d %d", &r, &g, &b);
	int ans = 1;
	ans = r * 100 + g * 10 + b;
	if (ans % 4 == 0) {
		puts("YES");
	} else {
		puts("NO");
	}		
}    
