#include <bits/stdc++.h>

using namespace std;

#define inf 1<<30
#define llong long long
#define usd unsigned
#define pqueue priority_queue
#define mp make_pair
#define pb push_back
#define fn fill_n
#define P pair<int, int>
struct data{
	int place;
	int cost;

	bool operator<(const data &ri) const{
		return cost < ri.cost;
	}
	bool operator>(const data &ri) const{
		return cost > ri.cost;
	}
};
int nw[9] = {0, 1, 0, -1, -1, 1, 1, -1, 0};
int nh[9] = {1, 0, -1, 0, 1, 1, -1, -1, 0};



int main(){
	int a;
	cin >> a;
	if(a == 7 || a == 5 || a == 3)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}