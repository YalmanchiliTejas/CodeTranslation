#include <bits/stdc++.h>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#else
#define TEST(n) ((void)0)
#endif

using namespace std;

const string ans[]={"First","Second"};
vector<int> A;
long long D[2][3000][3000];

long long solve(int t, int l, int r)
{
	if(l>r) return 0;
	if(D[t][l][r]!=0x7f7f7f7f7f7f7f7fLL) return D[t][l][r];
	if(t) {
		D[t][l][r]=max(solve(!t,l+1,r)+A[l],solve(!t,l,r-1)+A[r]);
	}
	else {
		D[t][l][r]=min(solve(!t,l+1,r)-A[l],solve(!t,l,r-1)-A[r]);
	}
	return D[t][l][r];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt", "r", stdin));
	TEST(freopen("output.txt", "w", stdout));
	TEST(freopen("debug.txt", "w", stderr));
	int N;
	cin>>N;
	A.resize(N);
	for(int i=0;i<N;i++) {
		cin>>A[i];
	}
	memset(D,0x7f,sizeof(D));
	cout<<solve(1,0,N-1)<<'\n';
	return 0;
}