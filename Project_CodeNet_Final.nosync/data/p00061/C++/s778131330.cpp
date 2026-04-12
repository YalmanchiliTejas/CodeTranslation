#include <string>
#include <iostream>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const double EPS = 1e-9;


int main(){
	int ac[100] = {0};
	int rank[32] = {0};

	int cntTeam = 0;
	while(true){
		int n, a;
		scanf("%d,%d", &n, &a);
		if(n == 0 && a == 0){
			break;
		}
		ac[n] = a;
		if(rank[a] == rank[a+1]){
			for(int i = 0; i < 31; i++){
				if(i <= a){
					rank[i]++;
				}
			}
		}
		cntTeam++;
	}

	int n;
	while(cin >> n){
		cout << rank[ac[n]] << endl;
	}
	
    return 0;
}