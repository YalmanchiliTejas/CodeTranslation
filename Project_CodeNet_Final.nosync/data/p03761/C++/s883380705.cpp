#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int INF = 1000000007;

int main(void){
	int n; cin>>n;
	int alp[50][26];
	for(int i=0;i<n;i++){
		for(int j=0;j<26;j++){
			alp[i][j] = 0;
		}
	}
	string S,ans;
	for(int i=0;i<n;i++){
		cin>>S;
		for(int j=0;j<S.size();j++){
			alp[i]['z' - S[j]]++;
		}
	}
	
	/*for(char i = 'z';i >= 'a';i--)cout<<i<<" ";
	cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<26;j++){
			cout<<alp[i][j]<<" ";
		}
		cout<<endl;
	}*/


	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	reverse(alphabet.begin(), alphabet.end());
	//cout<<alphabet<<endl;
	for(int j=0;j<26;j++){
		int cnt=0, k;
		int arr[60]={0};
		for(int i=0;i<n;i++){
			k = j;
			if(alp[i][j] != 0){
				cnt++;
				arr[i] = alp[i][j];
			}
		}
		//cout<<cnt<<" "<<k<<endl;
		if(cnt == n){
			sort(arr, arr+n);
			for(int m=0;m<arr[0];m++){
				ans += alphabet[k];
			}
		}
	}

	sort(ans.begin(), ans.end());

	printf("%s\n", ans.c_str());

	return 0;
}