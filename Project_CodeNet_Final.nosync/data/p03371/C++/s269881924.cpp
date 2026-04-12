#include <bits/stdc++.h>

using namespace std;

#define inf 1<<30
#define llong long long
#define usd unsigned
#define pqueue priority_queue
#define mp make_pair
#define pb push_back
#define fn fill_n
typedef pair<int, int> P;
typedef struct data{
	int now;
	int cost;
}data;
int nw[9] = {0, 1, 0, -1, -1, 1, 1, -1, 0};
int nh[9] = {1, 0, -1, 0, 1, 1, -1, -1, 0};




int main(){
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	cout << min(max(x,y)*c*2, min(min(x,y)*c*2 + (x<y?(y-x)*b:(x-y)*a), x*a+y*b)) << endl;

	return 0;
}