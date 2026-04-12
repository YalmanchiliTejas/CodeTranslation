#include<iostream>
#include<vector>
using namespace std;

const int MAX_N = 20;
int N;
vector<int> H(MAX_N);
void solve()
{
	int cnt = 1;
	int max = H.at(0);
	for(int i = 1; i < N; i++){
		if(max <= H.at(i)){
			max = H.at(i);
			cnt++;
		}
	}
  cout << cnt << endl;
}
int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> H.at(i);
	solve();
	return 0;
}
