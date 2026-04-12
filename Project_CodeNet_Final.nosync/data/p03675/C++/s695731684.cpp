#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
const int mod=1000000007;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	rep(i,n) cin >> a.at(i);
	int i=n/2,j=1,k=0;
	bool flg=true;
	if(n%2==0){
		b.at(i)=a.at(k);
		k++;
		flg=false;
		while(k<n){
			if(flg){
				b.at(i+j)=a.at(k);
				k++;
				j++;
				flg=false;
			}
			else{
				b.at(i-j)=a.at(k);
				k++;
				flg=true;
			}
		}
	}
	else{
		b.at(i)=a.at(k);
		k++;
		while(k<n){
			if(flg){
				b.at(i+j)=a.at(k);
				k++;
				flg=false;
			}
			else{
				b.at(i-j)=a.at(k);
				k++;
				j++;
				flg=true;
			}
		}
	}
	rep(i,n-1) cout << b.at(i) << " ";
	cout << b.at(n-1) << endl;
}