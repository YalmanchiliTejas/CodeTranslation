#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, l[200005], r[200005];
long long int a[200005];

long long int st[2000000], val[2000000];

int num=1<<18;

void UPDATE(int k, long long int b) {

	int pos = k + num-1;

	st[pos] = b;

	while (pos > 0) {
		pos =pos/ 2;
		st[pos] = max(st[pos * 2], st[pos * 2 + 1]);
	}
}

long long int INF = 9999999999999999;

void EVAL(int k, int l, int r) {

	st[k] += val[k];

	if (r > l) {
		val[k * 2] += val[k];
		val[k * 2 + 1] += val[k];
	}

	val[k] = 0;
}

long long int Q(int k, int l, int r, int a, int b) {

	EVAL(k, l, r);

	if (b < l || r < a) { return -INF; }

	if (a <= l && r <= b) { return st[k]; }
	
	
		long long int ret;
		ret = max( Q(2 * k , l, (l + r) / 2, a, b), Q(2 * k + 1, (l + r) / 2+1, r, a, b));
		st[k] = ret;
		return ret;

}

void ADD(int k, int l, int r, int a, int b, long long int W) {

	EVAL(k, l, r);

	if (b < l || r < a) { return; }

	if (a <= l && r <= b) { 
		val[k] += W;     EVAL(k, l, r); 
	}
	else {
		 ADD(k * 2 , l, (l + r) / 2, a, b, W); 
		 ADD(k * 2 + 1, (l + r) / 2 + 1, r, a, b, W); 
		 st[k] = max(st[k * 2], st[k * 2 + 1]);
		// cout << " add " << k <<" st= " <<st[k]<< endl;
	}

}

vector<pair<pair<int, int>, long long int> > V;


int main(void) {

	cin >> N >> M;

	/*num = 1;
	while (num <= N) { num *= 2; }
	*/

	for (int i = 1; i <= M; i++) {
		cin >> l[i] >> r[i] >> a[i];
		V.push_back(make_pair(make_pair(r[i], l[i]),a[i]));
	}
	V.push_back(make_pair(make_pair(2222222, 2222222), 999999999));

	//Q(1,1,num, l[i], r[i]) 
	//ADD(1,1,num,l[i],r[i],W);

	sort(V.begin(), V.end());

	/*for (int i = 1; i <= N; i++) {
		UPDATE(i, 0);
	}*/

	int p = 0;
	for (int i = 1; i <= N; i++) {
		long long int tmp = Q(1, 1, num, 1, i - 1);
		tmp = max((long long int) 0, tmp);
		//UPDATE(i,max(Q(1,1,num,i,i),Q(1, 1, num, 1, i - 1)));
		ADD(1, 1, num, i, i, tmp);
		while (V[p].first.first == i) {
			ADD(1, 1, num, V[p].first.second, V[p].first.first, V[p].second);
			p++;
		}
	}

	/*for (int i = 1; i <= N; i++) {
		cout << "dp[" << i << "]= " << Q(1,1,num,i,i) << endl;
	}*/

	/*for (int i = 1; i <= num*2; i++) {
		
		cout <<"st["<<i<<"]= "<<st[i]<<"   val[" <<i<<"]= "<< val[i] << endl;
		
	}*/
	
	cout << max((long long int) 0,Q(1, 1, num, 1, N)) << endl;

	return 0;
}