
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef struct pair<int,int> P;
typedef long long ll;
bool k[100001]={};
int a[100001]={};
int main() {
	int b[27];
	for(int i=0;i<27;i++)b[i]=100;
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;++i){
		cin>>s;
		int a[27]={};

		int ls=s.length();
		for(int j=0;j<ls;++j){
			int c=s[j]-97;
			a[c]++;
		}
		for(int j=0;j<27;++j){
			b[j]=min(a[j],b[j]);
		}
	}
	for(int i=0;i<27;i++){
		int k=i+97;
		char chr=k;
		for(int j=0;j<b[i];++j){
			cout<<chr;
		}
	}
	cout<<endl;
	return 0;
}
