#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int score[100];
	vector<int> answer;
	int n, ans;
	
	while (scanf("%d,%d", &n, &ans) * n != 0){
		score[n - 1] = ans;
		answer.push_back(ans);
	}
	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());
	reverse(answer.begin(), answer.end());
	
	while (scanf("%d", &n) != EOF){
		ans = score[n - 1];
		for (int i = 0; i < answer.size(); i++){
			if (answer[i] == ans){
				printf("%d\n", i + 1);
				break;
			}
		}
	}
	
	return 0;
}