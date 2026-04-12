#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007LL;

typedef pair<long long, long long> ii;
int main(){
	//freopen("i.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string s; int k;
	cin >> s;
	cin >> k;
	
	int nonzero = 0;
	
	int n = s.length();
	long long ans = 0;
	for(int i = 0;i < s.length();i++){
		int cur = s[i] - '0';
		
		//if(nonzero > k) break;
		if(i == 0){
			for(int d = 1;d < cur;d++){
				int target = k - nonzero;
				if(d != 0) target--;
				if(target < 0) continue;
				
				long long len = n - i  - 1;
				long long value = 1;
				for(long long j = 0;j < target;j++){
					value *= (len - j);
					value /= (j + 1);
				}
				for(long long j = 0;j < target;j++){
					value *= 9;
				}
				ans += value;
			}
		}
		else{
			for(int d = 0;d < cur;d++){
				int target = k - nonzero;
				if(d != 0) target--;
				if(target < 0) continue;
				
				long long len = n - i  - 1;
				long long value = 1;
				//cout << i << " " << d << " " << target << "\n";
				for(long long j = 0;j < target;j++){
					value *= (len - j);
					value /= (j + 1);
				}
				for(long long j = 0;j < target;j++){
					value *= 9;
				}
				ans += value;
			}
			
			for(int d = 1;d < 10;d++){
				int target = k;
				if(d != 0) target--;
				if(target < 0) continue;
				
				long long len = n - i  - 1;
				long long value = 1;
				for(long long j = 0;j < target;j++){
					value *= (len - j);
					value /= (j + 1);
				}
				for(long long j = 0;j < target;j++){
					value *= 9;
				}
				ans += value;
			}
		}
		if(cur != 0) nonzero++;
	}
	if(nonzero == k) ans++;
	cout << ans;
}
