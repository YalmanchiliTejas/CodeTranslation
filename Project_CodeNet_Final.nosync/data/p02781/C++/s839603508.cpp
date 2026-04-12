#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string N;
ll K;
ll combi(ll a, ll b){
	if(a<b) return 0;
	if(b==1) return a;
	if(b==2) return a*(a-1)/2;

	return a*(a-1)*(a-2)/6;
}
ll power(ll a){
	if(a==0) return 1;
	else return 9*power(a-1);
}

ll count(string N, ll K){
	ll d = N.size();

	ll res = 0;
	if(d>0){
		res += power(K)*combi(d-1, K);

		if(K==1){
			res +=  (N[0]-'0');
		}else{
			res += ((N[0]-'0')-1)*power(K-1)*combi(d-1, K-1);
			string S;
			//cout << S.size() <<endl;

			int k=1;
			while(N[k]-'0'==0) k++;

			for(int i=k;i<d;i++){
				S += N[i];
			}
			//cout << S <<endl;
			//cout << count(S, K-1) <<endl;
			res += count(S, K-1);
		}
	}
	
	return res;
}

int main(){
  	cin >> N >> K;
  	ll d = N.size();
  	if(d < K){
  		cout << 0 <<endl;
		return 0;
	}
	//cout << combi(2, 3) <<endl;
  	
  	cout << count(N, K) <<endl;

    
  	return 0;
}