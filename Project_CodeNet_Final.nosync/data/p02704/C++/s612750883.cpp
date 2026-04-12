#include"bits/stdc++.h"
using namespace std;
 
#define MAX 502
#define ull unsigned long long int 
int n;
int ty_r[MAX];
ull val_r[MAX];
int ty_c[MAX];
ull val_c[MAX];
bool tmp[MAX][MAX];
int emp[MAX];
ull ans[MAX][MAX];
void transpose(){
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++)swap(tmp[i][j],tmp[j][i]);
		swap(val_r[i],val_c[i]);
		swap(ty_r[i],ty_c[i]);
	}
}
void fi(long long int pos){
	memset(emp, 0, sizeof(emp));
	for (int j = 0; j < n; j++) {
		if (ty_c[j] == false) {
			emp[j] = n - 1;
			for (int k = 0; k < n; k++) emp[j]-=tmp[k][j];
		}
	}
	for (int i = 0; i < n; i++) {
		if (ty_r[i]) {
			if (((val_r[i]) >> pos) & 1ULL) {
				bool valid = false;
				for (int j = 0; j < n; j++) valid|=tmp[i][j];
				if (valid == false) {
					for (int j = 0; j < n; j++) {
						if (emp[j]>0) { 
							emp[j]--;
							tmp[i][j] = true;
							break;
						}
					}
				}
			}
		}
	}
}
void solve(ull pos) {
	memset(tmp, false, sizeof(tmp));
	for (int i = 0; i < n; i++) {
		if (ty_r[i]==false&&((val_r[i]) >> pos) & 1ULL) for (int j = 0; j < n; j++) tmp[i][j] = 1;
		if(ty_c[i]==false&&((val_c[i]) >> pos) & 1ULL) for (int j = 0; j < n; j++) tmp[j][i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ty_r[i] == ty_c[j]) {
				if (ty_r[i] == false) tmp[i][j] = ((val_r[i] >> pos) & 1ULL)| ((val_c[j] >> pos) & 1ULL);
				else tmp[i][j] = ((val_r[i] >> pos) & 1ULL)& ((val_c[j] >> pos) & 1ULL);
			}
		}
	}
	fi(pos);
	transpose();
	fi(pos);
	transpose();
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ans[i][j] += ((ull)(tmp[i][j]) << pos);
}
void fo(){
	puts("-1");
	exit(0);
}
void check() {
	for (int i = 0; i < n; i++) {
		ull AN = -1; ull O = 0; ull AN2 = -1; ull O2 = 0;
		for (int j = 0; j < n; j++) {
			AN &= ans[i][j];
			O |= ans[i][j];
			AN2&=ans[j][i];
			O2|=ans[j][i];
		}
		if (ty_r[i] == false&&AN != val_r[i]) fo();
		else if(ty_r[i] == true&&O!=val_r[i]) fo();
		if (ty_c[i] == false&&AN2 != val_c[i]) fo();
		else if (ty_c[i] && O2 != val_c[i]) fo();
	}
}
int main() {
		cin>>n;
		for (int i = 0; i < n; i++) scanf("%d", &ty_r[i]);
		for (int j = 0; j < n; j++) scanf("%d", &ty_c[j]);
		for (int i = 0; i < n; i++) scanf("%llu", &val_r[i]);
		for (int j = 0; j < n; j++) scanf("%llu", &val_c[j]);
		for (int i = 0; i < 64; i++) solve(i);
		check();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j)printf(" ");
				printf("%llu", ans[i][j]);
			}
			puts("");
		}
	return 0;
}