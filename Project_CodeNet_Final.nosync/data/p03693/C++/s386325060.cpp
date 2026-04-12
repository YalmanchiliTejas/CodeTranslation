/*input
4 3 2
*/
#include <bits/stdc++.h>
using namespace std;
int r, b, g;
int main(){
	scanf("%d %d %d", &r, &b, &g);
	puts((100 * r + 10 * b + g) % 4 == 0 ? "YES" : "NO");
}