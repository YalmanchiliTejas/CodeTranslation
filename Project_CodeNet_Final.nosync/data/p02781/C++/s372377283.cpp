#include<iostream>

int dp[101][4][2];

int main(void){
    std::string s;
    int nzc;
    std::cin >> s >> nzc;
    int mk = s.size();
    dp[0][0][0] = 1;
    for(int i = 0; i < mk; i++){
	for(int j = 0; j < 4; j++){
	    for(int k = 0; k < 2; k++){
		int d = s[i] - '0';
		for(int l = 0; l < 10; l++){
		    int ni = i + 1, nj = j, nk = k;
		    if(l != 0){
			nj++;
		    }
		    if(nj > nzc){
			continue;
		    }
		    if(k == 0){
			if(l > d) continue;
			if(l < d) nk = 1;
		    }
		    // std::cout << ni << " " << nj << " " << nk << " " << dp[ni][nj][nk] << std::endl;
		    dp[ni][nj][nk] += dp[i][j][k];
		}
	    }
	}
    }
    std::cout << dp[mk][nzc][1] + dp[mk][nzc][0] << std::endl;
    return 0;
}

