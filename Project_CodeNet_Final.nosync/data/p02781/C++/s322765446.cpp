#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define FOR(i, n) for(int i = 0; i < (int) n; i++)
#define all(x) x.begin(), v.end()
#define rall(x) x.rbegin(), x.rend()
#define PB push_back
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);

	string s; cin >> s;
	int n = (int) s.size();
	int k; cin >> k;
	ll ans = 0;
	if(k == 1){
		ans = 9*(n-1);
		ans += s[0]-'0';
		cout << ans << '\n';
	}else if(k == 2){
		ans = 81*(n-2)*(n-1)/2;
		string aux(n,'0');
		for(int i = 1; i <= s[0]-'0'; i++){
			aux[0] = i+'0';
			for(int j = 1; j < n; j++){
				aux[j]='1';
				while(aux <= s && aux[j] <= '9'){
					//cout << aux << '\n';
					ans++;
					aux[j]++;
				}
				aux[j] ='0';
			}
		}
		cout << ans << '\n';
	}else{
		for(int i = 0; i < n-3; i++)
			ans += 729*(i+1)*(i+2)/2;
		
		string aux(n,'0');
		for(int i = 1; i <= s[0]-'0'; i++){
			aux[0] = i+'0';
			for(int j = 1; j < n-1; j++){
				aux[j]='1';
				while(aux <= s && aux[j] <= '9'){
					for(int k = j+1; k < n; k++){
						aux[k]='1';
						while(aux <= s && aux[k] <= '9'){
							//cout << aux << '\n';
							ans++;
							aux[k]++;
						}
						aux[k] ='0';
					}
					aux[j]++;
				}
				aux[j] ='0';
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
