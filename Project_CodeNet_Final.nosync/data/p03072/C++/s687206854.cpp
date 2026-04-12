//abc124_b.cpp
//Fri Apr 19 21:02:47 2019

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int n;
	cin >> n;

	int h[n];
	int ans = 0;
	for (int i=0;i<n;i++){
		cin >> h[i];
		if (i==0){
			ans++;
		}else{
			int flag = 1;
			for (int j=0;j<i;j++){
				if (h[i]-h[j]<0){
					flag = 0;
					break;
				}
			}
			if (flag){
				ans++;
			}
		}
	}


	cout << ans << endl;
//	printf("%.4f\n",ans);
}