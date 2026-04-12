#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define fr first
#define sc second

int main(){
	static int n;
	static int x[200010];
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i ++){
		scanf("%d",&x[i]);
	}
	
	static vector<int> vec;
	for(int i = 0 ; i < n ; i ++){
		vec.push_back(x[i]);
	}
	sort(vec.begin(),vec.end());
	
	for(int i = 0 ; i < n ; i ++){
		int t = lower_bound(vec.begin(),vec.end(),x[i])-vec.begin();
		if(t < n/2){
			printf("%d\n",vec[n/2]);
		}
		else {
			printf("%d\n",vec[n/2-1]);
		}
	}
}

