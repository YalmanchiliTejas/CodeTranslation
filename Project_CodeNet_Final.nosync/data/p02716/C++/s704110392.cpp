#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#include <array>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
int n;
ll a[200020];
void solve(int l, int r, vector<ll> v[2][2]){
	if(l>r){
		for(int i=0; i<2; i++) for(int j=0; j<2; j++) v[i][j].push_back(0);
		return;
	}else if(l==r){
		for(int i=0; i<2; i++) for(int j=0; j<2; j++) v[i][j].push_back(0);
		v[1][1].push_back(a[l]);
		return;
	}else if(l+1==r){
		for(int i=0; i<2; i++) for(int j=0; j<2; j++) v[i][j].push_back(0);
		v[1][1].push_back(max(a[l], a[r]));
		v[1][0].push_back(a[l]);
		v[0][1].push_back(a[r]);
		return;
	}
	vector<ll> v1[2][2], v2[2][2];
	int m=(l+r)/2;
	solve(l, m, v1);
	solve(m+1, r, v2);
	v[0][0].resize(1+(r-l)/2);
	v[0][1].resize(1+(r-l+1)/2);
	v[1][0].resize(1+(r-l+1)/2);
	v[1][1].resize(1+(r-l+2)/2);
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			for(int k=0; k<2; k++){
				int p=v1[i][k].size()-1, q=v2[k^1][j].size()-1;
				while(p>=0 && q>=0){
					v[i][j][p+q]=max(v[i][j][p+q], v1[i][k][p]+v2[k^1][j][q]);
					if(p==0 && q==0) break;
					else if(p==0) q--;
					else if(q==0) p--;
					else{
						if(v1[i][k][p-1]+v2[k^1][j][q]>v1[i][k][p]+v2[k^1][j][q-1]) p--;
						else q--;
					}
				}
			}
		}
	}
	return;
}
int main()
{
	scanf("%d", &n);
    const ll geta=1e9+7;
	for(int i=0; i<n; i++){
		scanf("%lld", &a[i]);
        a[i]+=geta;
	}
	vector<ll> ans[2][2];
	solve(0, n-1, ans);
	cout<<ans[1][1][n/2]-geta*(n/2)<<endl;
	return 0;
}
