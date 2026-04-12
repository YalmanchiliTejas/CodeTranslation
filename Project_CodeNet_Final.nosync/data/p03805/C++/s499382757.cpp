#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <climits>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ve vector
#define umap unordered_map
#define iter iterator

int N,M;
bool dp[10][10];
int arr[10];
void solve() {
	int i,x,y;
	cin>>N>>M;
	for(int i=0;i<M;i++) {
		cin>>x>>y;
		dp[x-1][y-1]=1;
		dp[y-1][x-1]=1;
	}
	for(int i=0;i<N;i++) arr[i]=i;
	int res=0;
	do {
		if(arr[0]!=0) continue;
		for(i=0;i<N-1;i++) {
			if(dp[arr[i]][arr[i+1]]==0) break;
		}
		if(i==N-1) res++;
	} while (next_permutation(arr,arr+N));
	cout<<res<<endl;
}

int main() {
    solve();
    return 0;
}