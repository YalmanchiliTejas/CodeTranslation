#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define MAX 32000

int N;
int A[1005];
bool is_prime[MAX];
vector<int> PRIME;
map<int,bool> MAP;

int main(){

	PRIME.push_back(2);

	for(int i = 3; i < MAX; i += 2){

		is_prime[i] = true;
	}

	for(int i = 3; i < MAX; i += 2){

		if(!is_prime[i])continue;
		PRIME.push_back(i);

		for(int k = 2*i; k < MAX; k += i){

			is_prime[k] = false;
		}
	}

	scanf("%d",&N);

	//32000以上の素数を探す
	for(int i = 0; i < N; i++){

		scanf("%d",&A[i]);

		if(A[i] == 1)continue;

		auto at = MAP.find(A[i]);

		if(at != MAP.end())continue; //出現済
		MAP[A[i]] = true;

		bool FLG = true;

		for(int k = 0; k < PRIME.size(); k++){

			if(A[i]%PRIME[k] == 0){

				FLG = false;
				break;
			}
		}
		if(FLG){

			PRIME.push_back(A[i]);
		}
	}

	ll ans = 0,tmp_sum;

	for(int i = 0; i < PRIME.size(); i++){

		tmp_sum = 0;
		for(int k = 0; k < N; k++){
			if(A[k]%PRIME[i] == 0){
				tmp_sum += A[k];
			}
		}
		ans = max(ans,tmp_sum);
	}

	printf("%lld\n",ans);

	return 0;
}

