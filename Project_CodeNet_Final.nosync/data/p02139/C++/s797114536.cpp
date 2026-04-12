#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, q;
	cin >> n >> q;
	int memo=0, tmp1, tmp2;
	for (int i = 0; i < q; ++i)
	{
		cin >> tmp1 >> tmp2;
		if(tmp1==0)
		{
			if(memo==0) cout << tmp2 << endl;
			else if(memo+tmp2-1>n) cout << memo+tmp2-1-n << endl;
			else cout << memo+tmp2-1 << endl;
		}
		else
		{
			if(memo==0) memo=tmp2+1;
			else if(tmp2<=n-memo) memo+=tmp2; //cut left
			else memo=tmp2-n+memo; //cut right
		}
	}
	return 0;
}
