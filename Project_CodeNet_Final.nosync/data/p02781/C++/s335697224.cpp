#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

//Nは桁数が大きい場合があるので文字列として受け取る
string N;
vector<int> n;  //Nの各桁の数字を格納するベクター
ll dp[101][2][5];

int main(){
	cin>>N;
	int k;cin>>k;

  	//ベクターnを構成
  	for(auto a : N){
    	n.push_back(a-'0');
  	}
  	int l = N.size();  //nの長さ

  	dp[0][0][0] = 1LL;  //初期条件。他は0で初期化されている
	for(int i = 0; i < l; i++){
		for(int smaller = 0; smaller < 2; smaller++){
			for(int j = 0; j < k + 1; j++){
				for(int x = 0; x <= (smaller ? 9 : n[i]); x++){
					if (x != 0){
						dp[i + 1][smaller || x < n[i]][j + 1] += dp[i][smaller][j];          
					}
					else{
						dp[i + 1][smaller || x < n[i]][j] += dp[i][smaller][j];          
					}
				}
			}
		}
	}

  	cout << dp[l][0][k] + dp[l][1][k] << endl;
  	return 0;
}