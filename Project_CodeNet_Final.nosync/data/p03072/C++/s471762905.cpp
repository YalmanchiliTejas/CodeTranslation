#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<utility>
#include<climits>
#define MAX 1000000
#define pb push_back
#define f first
#define s second

using namespace std;

typedef pair<int, int> pii;
typedef map<int, int> mapint;

int32_t main(){
	int n;
	cin>>n;
	int maxh = 0;
	int ans = 0;
	for(int i=0; i<n; i++) {
		int temp;
		cin>>temp;
		if(temp>=maxh) ++ans;
		maxh = max(temp, maxh);
	}
	cout<<ans<<endl;
	return 0;
}
