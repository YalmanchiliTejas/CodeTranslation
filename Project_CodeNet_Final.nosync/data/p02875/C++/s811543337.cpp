#include<iostream>
using namespace std;

/*int l[100001];
int r[100001];
int templ[100001];
int tempr[100001];
void margesort(int a[], int a_len, int left, int right);
*/
long long modpow(long long a, long long n, long long mod);
long long modinv(long long a, long long mod);


int main(){
	//C
	long long int n;
	long long int p = 998244353;
	cin >> n;
	n = n / 2;
	long long int counter = 0;
	long long int comb = 1;
	int i;
	for (i = 0; i < n; i++) {
		counter = (counter + 2 * comb) % p;
		comb = (comb * 2 * (2 * n - i)) % p;
		comb = (comb * modinv(i + 1, p)) % p;
	}
	long long int absum = 1;
	for (i = 0; i < 2 * n; i++) {
		absum = (absum * 3) % p;
	}
	absum = (absum - counter + p) % p;
	cout << absum;
	return 0;
	/*int n;

	int i;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> l[i];
		cin >> r[i];
	}
	margesort(l, n, 0, n - 1);
	int minR, min2R, maxL, max2L;
	minR = 1000000001;
	min2R = 1000000001;
	maxL = 0;
	max2L = 0;
	int maxwidth = 0;
	for (i = 0; i < n; i++) {
		if (r[i] <= minR) {
			min2R = minR;
			minR = r[i];
		}
		else if (r[i] < min2R) {
			min2R = r[i];
		}
		if (l[i] >= maxL) {
			max2L = maxL;
			maxL = l[i];
		}
		else if (l[i] > max2L) {
			max2L = l[i];
		}
	}

	int ll, rr;
	for (i = 0; i < n; i++) {
		if (r[i] == minR) {
			rr = min2R;
		}
		else {
			rr = minR;
		}
		if (l[i] == maxL) {
			ll = max2L;
		}
		else {
			ll = maxL;
		}
		if (rr - ll >= 0) {
			if (rr - ll + r[i] - l[i] + 2 > maxwidth) {
				maxwidth = rr - ll + r[i] - l[i] + 2;
			}
		}
		else {
			if (r[i] - l[i] + 1 > maxwidth) {
				maxwidth = r[i] - l[i] + 1;
			}
		}
	}
	
	min2R = r[n - 1];
	max2L = l[n - 1];
	int j,w1,w2;
	for (i = n-2; i > 0; i--) {
		if (r[i] < min2R) {
			min2R = r[i];
		}
		if (l[i] > max2L) {
			max2L = l[i];
		}
		maxL = l[i - 1];
		if (r[i] == minR) {
			minR = 1000000001;
			for (j = 0; j < i; j++) {
				if (r[j] < minR) {
					minR = r[j];
				}
			}
		}
		if (min2R - max2L >= 0) {
			w2 = min2R - max2L + 1;
		}
		else {
			w2 = 0;
		}
		if (minR - maxL >= 0) {
			w1 = minR - maxL + 1;
		}
		else {
			w1 = 0;
		}
		if (w1 + w2 > maxwidth) {
			maxwidth = w1 + w2;
		}
	}
	cout << maxwidth;
	return 0;
	*/
}
/*
void margesort(int a[], int a_len, int left, int right){
	int i, j, mid, L, R;

	if (right <= left)
		return;

	mid = (left + right) / 2;
	margesort(a, mid, left, mid);
	margesort(a, a_len - mid, mid + 1, right);

	for (i = left; i <= mid; i++) {
		templ[i] = a[i];
		tempr[i] = r[i];
	}
	for (i = mid + 1, j = right; i <= right; i++, j--) {
		templ[i] = a[j];
		tempr[i] = r[j];
	}
	L = left;
	R = right;

	for (i = left; i <= right; i++)
	{
		if (templ[L] <= templ[R])
		{
			a[i] = templ[L];
			r[i] = tempr[L];
			L++;
		}
		else
		{
			a[i] = templ[R];
			r[i] = tempr[R];
			R--;
		}
	}*/
	// a^n mod を計算する

long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

// a^{-1} mod を計算する
long long modinv(long long a, long long mod) {
	return modpow(a, mod - 2, mod);
}

