#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
typedef long long ll;

using namespace std;

int N, M;
int node[10][10] = {0};
int res = 0;

void dfs(int key, bool on[], int cnt){
    for (int i = 2; i <= N; i++){
	if ((node[key][i] == 1) && (!on[i])){
	    if (cnt+1 == N){
		res++;
	    } else {
		on[i] = true;
		cnt++;
		dfs(i, on, cnt);
		on[i] = false;
		cnt--;
	    }
	}
    }
}

int main(){
    cin >> N >> M;
    for (int i = 1; i <= M; i++){
	int a, b;
	cin >> a >> b;
	node[a][b] = 1;
	node[b][a] = 1;
    }
    bool on[10];
    for (int i = 0; i < 10; i++) on[i] = false;

    on[1] = true;
    dfs(1, on, 1);

    cout << res << endl;

    return 0;
}
