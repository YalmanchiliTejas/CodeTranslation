#include <bits/stdc++.h>
using namespace std;
using Pi = pair < int , int >;

template < typename T > 
struct BIT
{
	vector < T > dat;

	BIT (int n)
	{
		dat.assign(n + 1, 0);
	}
	
	void add(int k, T x)
	{
		k++;
		while ( k <= dat.size() ) {
			dat[k] += x;
			k += k & -k;
		}
	}

	T query(int k)
	{
		T sum = 0;
		k++;
		while ( k > 0 ) {
			sum += dat[k];
			k -= k & -k;
		}
		return ( sum );
	}

	int lower_bound(T x)
	{
		int l, r;
		l = -1, r = dat.size();
		while ( l + 1 < r ) {
			int m = (l + r) / 2;
			if ( query(m) >= x ) r = m;
			else l = m;
		}
		return ( r );
	}
};

int main()
{
	int N;
	int A[100005];
	Pi dat[100005];

	map < Pi , int > idx;
	cin >> N;

	for ( int i = 0; i < N; i++ ) {
		cin >> A[i];
		dat[i] = Pi(A[i], -i);
	}
	sort(dat, dat + N);
	
	for ( int i = 0; i < N; i++ ) {
		idx[dat[i]] = i;
	}
	
	BIT < int > tree(N);	
	int ans = 0;
	for ( int i = 0; i < N; i++ ) {
		int pos = idx[Pi(A[i], -i)];
		int value = tree.query(pos);
		
		if ( value == 0 ) {
			ans++;
		} else {
			tree.add(tree.lower_bound(value), -1);
		}
		tree.add(pos, 1);
	}

	cout << ans << endl;

	return ( 0 );
}
