#include <iostream>
using namespace std;

const int N = 100000;
int t[N][2];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	while(cin >> n && n){
		
		int x;
		cin >> x;
		t[0][0] = x;
		
		int size;
		t[0][1] = size = 1;
		
		for(int i = 0; i < n - 1; ++i){
			cin >> x;
			if(i % 2 == 0){
				if(t[size - 1][0] == x){
					t[size - 1][1] ++;
				}
				else {
					if(size >= 2){
						t[size - 2][1] += t[size - 1][1] + 1;
						size --;
					}
					else {
						t[size - 1][0] = x;
						t[size - 1][1]++;
					}
				}
			}
			else {
				if(t[size - 1][0] == x){
					t[size - 1][1] ++;
				}
				else {
					t[size][0] = x;
					t[size++][1] = 1;
				}
			}
		}
		
		int ans = 0;
		for(int i =0; i < size; ++i){
			ans += t[i][0] == 0 ? t[i][1] : 0;
		}
		
		cout << ans << endl;
	}
	
	return 0;
}