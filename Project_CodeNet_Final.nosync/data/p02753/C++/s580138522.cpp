#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <map>
#include <vector>
#include <queue>
#include <stack>
  
using namespace std;
  
typedef long long ll;
typedef string ss;

#define speed ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int N = 1e2 + 5, INF = int(2e9) + 1;

ss s;

int ans, cnt;

int main(){
	speed;
	cin >> s;
	for(int i = 0; i <= s.size(); i++){
		if(s[i] == 'A'){
			ans++;
		}
		else if(s[i] == 'B'){
			cnt++;
		}
	}
	if(cnt == 2 or ans == 2){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
}