#include<bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 13;
int n, a[maxN], pos[maxN], arr[maxN];
bool cmp (int i, int j) {
    if (a[i] != a[j])
	return a[i] < a[j];
    return i < j;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);;
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) 
	cin >> a[i];
    iota(arr, arr + n, 0);
    sort(arr, arr + n, cmp);
    int val1 = a[arr[(n - 1)/ 2]], val2 = a[arr[n / 2]];
    for (int i = 0; i < n; i++)
	pos[arr[i]] = i;
    for (int i = 0; i < n; i++) {
	if (pos[i] < n / 2)
	    cout << val2 << '\n';
	else
	    cout << val1 << '\n';
    }
}
