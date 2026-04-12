#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define xmod (ll)(1e9+7)
using namespace std;

ll len,dp_l[10005][105],d,dp_s[10005][105],sum,num;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin >> s >> d; len=s.length();
	for (int i=0;i<s[0]-'0';i++){
		dp_l[0][i%d]++;
	} 
	dp_s[0][(s[0]-'0')%d]++; 
	for (int i=1;i<len;i++){
		for (int j=0;j<d;j++){
			for (int k=0;k<=9;k++){
				dp_l[i][(k+j)%d]+=dp_l[i-1][j];
				dp_l[i][(k+j)%d]%=xmod;
			}
			for (int k=0;k<s[i]-'0';k++){
				dp_l[i][(k+j)%d]+=dp_s[i-1][j];
				dp_l[i][(k+j)%d]%=xmod;
			}
			dp_s[i][(s[i]-'0'+j)%d]=dp_s[i-1][j];
		}
	}
	num=dp_l[len-1][0]+dp_s[len-1][0]-1;
	if (num < 0)
	num+=xmod;
	cout << num%xmod << "\n";
    return 0;
}