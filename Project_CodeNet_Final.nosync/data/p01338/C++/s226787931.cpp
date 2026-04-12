#include<iostream>
using namespace std;

int main(){
  int dp[5][1<<16];
  int grid[5][5];
  int bit[5];
  int casenum;
  int score[] = {0,0,60,70,80};

  cin >> casenum;
  while(casenum--){
    for(int i=0;i<5;i++)
      for(int j=0;j<5;j++)cin >> grid[i][j];

    for(int i=0;i<5;i++){
      bit[i] = 0;
      for(int j=0;j<5;j++){
	bit[i] |= (grid[i][j] << (3*j));
      }
    }

    for(int i=0;i<5;i++)
      for(int j=0;j<(1<<15);j++)dp[i][j] = -1;

    dp[0][bit[0]] = 0;

    for(int i=0;i<4;i++){
      int tmp[5];
      for(int j=0;j<5;j++){
	tmp[j] = ( bit[i+1]%( 1<<(3*(j+1)) ) ) >> (3*j);
      }

      for(int j=0;j<(1<<8);j++){
	int change[4];
	for(int k=0;k<4;k++){
	  change[k] = ( j%( 1<<(2*(k+1)) ) ) >> (2*k);
	}

	for(int k = 0;k<(1<<15);k++){
	  if(dp[i][k]>=0){
	    int pre[5];     
	    for(int l=0;l<5;l++){
	      pre[l] = ( k%( 1<<(3*(l+1)) ) ) >> (3*l);
	    }
	    int next[5];
	    int sum = 0;
	    for(int l=0;l<5;l++){
	      if(pre[l]){
		if(l!=4)pre[l] += change[l];
		if(pre[l]>4)pre[l] -= 4;
		if(l)pre[l] += change[l-1];
		if(pre[l]>4)pre[l] -= 4;
		sum += score[pre[l]];
	      }

	      next[l] = tmp[l];
	      if(next[l]){
		if(l!=4)next[l] += change[l];
		if(next[l]>4)next[l] -= 4;
		if(l)next[l] += change[l-1];
		if(next[l]>4)next[l] -= 4;
		next[l] %= 5;
	      }
	    }
	    int bitnext = 0;
	    for(int l=0;l<5;l++){
	      bitnext |= (next[l] << (3*l) );
	    }
	    /*
	    if(dp[i+1][bitnext]<dp[i][k] + sum){
	      cout << sum << endl;
	      for(int l=0;l<5;l++)cout << next[l] << " ";
	      cout << endl;
	      for(int l=0;l<4;l++)cout << change[l] << " ";
	      cout << endl;
	    }
	    */
	    dp[i+1][bitnext] = max(dp[i+1][bitnext],dp[i][k] + sum);
	  }
	}
      }
    }

    int ans = 0;
    for(int i=0;i<(1<<15);i++){
      if(dp[4][i]>=0){
	int hoge = 0;
	//cout << "[";
	for(int j=0;j<5;j++){
	  int tmp =  ( i%( 1<<(3*(j+1))) ) >> (3*j);
	  //cout << tmp << " ";
	  hoge += score[tmp];
	}	
	//cout<< "]" << endl;
	ans = max(ans,dp[4][i] + hoge);
      }
    }
    cout << ans << endl;
  }
}
    