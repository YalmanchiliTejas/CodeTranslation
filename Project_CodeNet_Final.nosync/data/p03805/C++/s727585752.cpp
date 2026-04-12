#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<set>
#include<utility>
#include<typeinfo>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD=1e9+7;

int main(){

	int n, m, a[30], b[30], c[10], ans=0;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >> a[i] >> b[i];
	}
	for(int i=0; i<n; i++){
		c[i]=i+1;
	}
	bool flag;
	do{
		if(c[0]==1){
			for(int i=0; i<n-1; i++){
				for(int j=0; j<m; j++){
					flag=false;
					if(c[i]==a[j] && c[i+1]==b[j] || c[i]==b[j] && c[i+1]==a[j]){
						flag=true;
						break;
					}
				}
				if(!flag){
					break;
				}
			}
			if(flag){
				ans++;
			}
		}
	}while(next_permutation(c, c+n));
	cout << ans << endl;

	return 0;
}
