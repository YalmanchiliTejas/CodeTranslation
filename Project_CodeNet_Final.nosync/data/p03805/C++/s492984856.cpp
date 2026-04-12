#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
bool used [8];
int perm[8];
int a[28], b[28];

int permutation(int pos, int n, int m){
	if(pos == n){
		bool check = true;
		for(int i=0;i<n-1;i++){
			bool check2 = false;//辺がないときにfalse
			for(int j=0;j < m;j++){
				if(a[j]-1 == perm[i] && b[j]-1 == perm[i+1]) check2 = true;
				if(b[j]-1 == perm[i] && a[j]-1 == perm[i+1]) check2 = true;
			}
			check = check2;
			if(!check) break;
		}
		if(check) return 1;
		else return 0;
	}
	int ans = 0;
	for(int i=0; i<n;i++){
		if(!used[i]){
			perm[pos] = i;
			used[i] = true;
			ans += permutation(pos + 1, n, m);
			used[i] = false;
		}
	}
	return ans;
}
int main(){
	int N, M;
	cin >> N >> M;
	for(int i=0;i<M;i++){
		cin >> a[i] >> b[i];
	}
	used[0] = true;
	perm[0] = 0;
	cout << permutation(1,N,M) << endl;
}