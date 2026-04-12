#include<bits/stdc++.h>
//#define INF 1e9
using namespace std;
long long int arr[200001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int n;
	cin >> n;
	long long int total = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		total += arr[i] % 1000000007;
		total %=1000000007;
	}
	long long int sum = 0;
	long long int m_sum = 0;
	for (int i = 0; i < n; i++) {
		m_sum += arr[i];
		m_sum = m_sum  % 1000000007;
		sum = sum + arr[i] * (total - m_sum)%1000000007;
      	if(sum<0)sum+=1000000007;
		sum = sum % 1000000007;
 
	}
	cout << sum % 1000000007;
	return 0;
}