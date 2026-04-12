#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

int main(){
	while(true){
		int n, m;
		scanf("%d%d", &n, &m);
		if(n == 0 && m == 0){ break; }
		priority_queue<int, vector<int>, greater<int> > timestamps;
		for(int i = n + m; i > 0; i--){
			int input;
			scanf("%d", &input);
			timestamps.push(input);
		}
		int maxlen = 0, prevtime = 0;
		while(!timestamps.empty()){
			int t = timestamps.top();
			if(t - prevtime > maxlen){ maxlen = t - prevtime; }
			prevtime = t;
			timestamps.pop();
		}
		printf("%d\n", maxlen);
	}
	return 0;
}