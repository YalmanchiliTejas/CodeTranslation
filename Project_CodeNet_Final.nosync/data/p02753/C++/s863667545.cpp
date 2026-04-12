#include<iostream>
#include<iomanip>
#include<cassert>
#include<math.h>
#include<complex>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

string S;
int main(){
    cin>>S;
	ll ans=0;
	if(S[0]!=S[1])ans++;
	if(S[1]!=S[2])ans++;
	if(ans>0){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
    return 0;
}