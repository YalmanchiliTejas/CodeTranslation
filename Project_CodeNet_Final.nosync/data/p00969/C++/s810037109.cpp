#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 5005

int N;
int table[NUM];
int dp[NUM][NUM];

int main(){

	scanf("%d",&N);

	if(N == 2){

		printf("2\n");
		return 0;
	}

	for(int i = 0; i < N; i++){
		for(int k = 0; k < N; k++){
			if(k == i){

				dp[i][k] = 1;
			}else{

				dp[i][k] = 2;
			}
		}
	}

	for(int i = 0; i < N; i++){

		scanf("%d",&table[i]);
	}
	sort(table,table+N);

	int ans = 2;
	int diff,right;

	for(int mid = 1; mid <= N-2; mid++){
		right = mid+1;
		for(int left = mid-1; left >= 0; left--){
			diff = table[mid]-table[left];
			while(right < N && table[right]-table[mid] < diff){
				right++;
			}
			if(table[right]-table[mid] == diff){

				dp[mid][right] = dp[left][mid]+1;
				ans = max(ans,dp[mid][right]);
			}
		}
	}

	printf("%d\n",ans);

	return 0;
}

