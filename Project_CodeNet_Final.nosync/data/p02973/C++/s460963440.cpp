#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
typedef long long ll;
typedef pair<int,int>pii;
const int N = 1e5;
int arr[N+100];
multiset<int>st;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=1;i<=n;i++){
		auto it = st.lower_bound(arr[i]);
		if(it==st.begin())st.insert(arr[i]);
		else{
			it--;
			st.erase(it);
			st.insert(arr[i]);
		}
	}
	printf("%d\n",(int)st.size());
}
