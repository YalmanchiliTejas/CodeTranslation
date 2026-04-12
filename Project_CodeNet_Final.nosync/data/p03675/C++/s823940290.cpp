#include <bits/stdc++.h>
using namespace std;

int N,l,r,A[300100];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	
	l = r = 150000; l--;
	cin >> N;
	for(int i = 1;i<=N;i++)	if(i%2) cin >> A[r++]; else cin >> A[l--];
	if(N%2)	for(int i = r-1;i>l;i--) cout << A[i] << ' ';
	else for(int i = l+1;i<r;i++) cout << A[i] << ' ';
}