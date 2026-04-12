#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
vector<vector<int>> T(9);
bitset<9> dp;

int rec(int corrent = 1, int count = 1){
    
    if(count == N){
        return 1;
    }
    
    int res = 0;
    for(int i = 0; i < T[corrent].size(); ++i){
        if(corrent == 1){
            dp.reset(), dp.set(corrent);
        }
        if(!dp[T[corrent][i]]){
            dp.set(T[corrent][i]);
            res += rec(T[corrent][i], count + 1);
            dp.reset(T[corrent][i]);
        }
    }
    
    return res;
}

int main(void){
    
	cin >> N >> M;
	for(int i = 0; i < M; ++i){
	    int temp1, temp2;
	    cin >> temp1 >> temp2;
	    T[temp1].push_back(temp2);
	    T[temp2].push_back(temp1);
	}
	
	int ans = 0;
	ans += rec();
	cout << ans << endl;
    
    return 0;
}