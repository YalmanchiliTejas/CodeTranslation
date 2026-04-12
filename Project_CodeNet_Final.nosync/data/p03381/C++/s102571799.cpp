#include <bits/stdc++.h>
using namespace std;

#define llong long long
#define inf 999999999
#define mp make_pair
#define pb push_back
#define fn fill_n
typedef pair<int, int> P;
typedef pair<P, int> PP;
typedef pair<PP, int> PPP;
typedef struct data{
	int now;
	int cost;
}data;
int nh[4] = {1, 0, -1, 0};
int nw[4] = {0, 1, 0, -1};





int main(){
	int n, x[200001];
	int a[200001];
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> x[i];
		a[i] = x[i];
	}

	sort(a+1, a+n+1);
	int middles[4];
	for(int i = 0; i < 4; i++) middles[i] = a[n/2-1+i];

	for(int i = 1; i <= n; i++){
		if(x[i] <= middles[1]){
			cout << middles[2] << endl;
		}else if(x[i] >= middles[2]){
			cout << middles[1] << endl;
		}
	}

	return 0;
}