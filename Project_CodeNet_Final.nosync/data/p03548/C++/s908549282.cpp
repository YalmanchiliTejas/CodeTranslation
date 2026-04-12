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
int a,b,c,d, A[100], B[100], C[100][100], D[100][100][100];
string s, t, r;




int main(){
	cin >> a >> b >> c;
	cout << (a-c)/(b+c) << endl;
	return 0;
}