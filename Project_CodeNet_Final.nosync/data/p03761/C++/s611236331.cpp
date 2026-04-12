#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;



int main() {
	int n,ans[27];
	cin>>n;
	for(int i=0;i<27;i++){
		ans[i]=1<<30;
	}
	for(int i=0;i<n;i++){
		vector<int>kari(27,0);
		string s;
		cin>>s;
		for(int j=0;j<s.size();j++){
			kari[s.at(j)-'a']++;
		}
		for(int j=0;j<27;j++){
			ans[j]=min(ans[j],kari[j]);
		}
	}
	bool flag=0;
	for(int i=0;i<27;i++){
		if(ans[i]>0){
			for(int j=0;j<ans[i];j++){
				cout << char (i+'a');
				flag=1;
			}
		}
	}
	cout << (flag ? "":" ");
}