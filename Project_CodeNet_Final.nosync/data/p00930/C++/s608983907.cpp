// ACM-ICPCアジア地区予選2014 G. Flipping Parentheses

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1<<19;
int segMin[2*N-1];
int segAdd[2*N-1];
int segSum[2*N-1];

void add(int l, int r, int val, int idx = 0, int rangeL = 0, int rangeR = N){
	if(rangeR <= l || r <= rangeL) return;
	if(l <= rangeL && rangeR <= r){
		segAdd[idx] += val;
		while(idx){
			idx = (idx-1)/2;
			segMin[idx] = min(segMin[2*idx+1]+segAdd[2*idx+1], segMin[2*idx+2]+segAdd[2*idx+2]);
		}
	} else {
		int rangeM = (rangeL+rangeR)/2;
		add(l, r, val, 2*idx+1, rangeL, rangeM);
		add(l, r, val, 2*idx+2, rangeM, rangeR);
	}
}

int getMin(int l, int r, int idx = 0, int rangeL = 0, int rangeR = N){
	if(rangeR <= l || r <= rangeL) return 1000000007;
	if(l <= rangeL && rangeR <= r) return segMin[idx]+segAdd[idx];
	int rangeM = (rangeL+rangeR)/2;
	return min(getMin(l, r, 2*idx+1, rangeL, rangeM), getMin(l, r, 2*idx+2, rangeM, rangeR)) + segAdd[idx];
}

void change(int pos, int val){
	int idx = pos+N-1;
	int add = val-segSum[idx];
	segSum[idx] = val;
	while(idx){
		idx = (idx-1)/2;
		segSum[idx] += add;
	}
}

int getSum(int l, int r, int idx = 0, int rangeL = 0, int rangeR = N){
	if(rangeR <= l || r <= rangeL) return 0;
	if(l <= rangeL && rangeR <= r) return segSum[idx];
	int rangeM = (rangeL+rangeR)/2;
	return getSum(l, r, 2*idx+1, rangeL, rangeM)+getSum(l, r, 2*idx+2, rangeM, rangeR);
}

int main(){
	int n, q;
	char str[300001];
	while(~scanf("%d %d", &n, &q)){
		memset(segMin, 0, sizeof(segMin));
		memset(segAdd, 0, sizeof(segAdd));
		memset(segSum, 0, sizeof(segSum));
		scanf("%s", str);
		for(int i=0;i<n;i++){
			if(str[i] == '('){
				add(i, n, 1);
			} else {
				add(i, n, -1);
				change(i, 1);
			}
		}
		for(int i=0;i<q;i++){
			int idx; scanf("%d", &idx); --idx;
			if(idx == 0 || idx == n-1){
				printf("%d\n", idx+1);
			} else if(str[idx] == '('){
				change(idx, 1);
				add(0, idx, 2);
				str[idx] = ')';
				int L = 0, R = n-1;
				while(R-L>1){
					int mid = (L+R)/2;
					if(getSum(0, mid) > 0) R = mid;
					else                   L = mid;
				}
				change(L, 0);
				add(0, L, -2);
				str[L] = '(';
				printf("%d\n", L+1);
			} else {
				change(idx, 0);
				add(0, idx, -2);
				str[idx] = '(';
				int L = 0, R = idx+1;
				while(R-L>1){
					int mid = (L+R)/2;
					if(getMin(mid, idx+1) >= 0) R = mid;
					else                        L = mid;
				}
				change(R, 1);
				add(0, R, 2);
				str[R] = ')';
				printf("%d\n", R+1);
			}
		}
	}
}