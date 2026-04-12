#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int,int> PII;
typedef pair<long long,long long> PLL;

int main(){
	int n;
	cin>>n;
	int h[100];
	for (int i = 0; i < n; ++i){
		cin>>h[i];
	}

	int count=0;
	for (int i = 0; i < n; ++i){
		bool flag=true;
		for (int j = 0; j < i; ++j){
			if(h[j]>h[i]){
				flag=false;
			}
		}
		if(flag)
			count++;
	}

	cout<<count<<endl;


}