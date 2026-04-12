#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define fr first
#define sc second

int main(){
	int n;
	int h[22];
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i ++){
		scanf("%d",&h[i]);
	}
	
	int ret = 0;
	int MAX = 0;
	for(int i = 0 ; i < n ; i ++){
		if(MAX <= h[i]){
			ret ++;
			MAX = h[i];
		}
	}
	cout << ret << endl;
}