#include <iostream>
#include <vector>

using namespace std;

int N;
int p[205];
vector<int> ans;

int main(void)
{
	cin >> N;
	for(int i = 0; i < N; i++) cin >> p[i];
	
	for(int i = 0; i < N; i++){
		ans.push_back(1);
		for(int j = 0; j < N-1; j++){
			if(p[j] > p[j+1]){
				ans.push_back(N-1);
				int t = p[j];
				p[j] = p[j+1];
				p[j+1] = t;
			}
			ans.push_back(1);
		}
	}
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << endl;
	}
	return 0;
}