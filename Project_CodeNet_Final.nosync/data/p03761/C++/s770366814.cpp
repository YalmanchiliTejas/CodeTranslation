#include<bits/stdc++.h>
using namespace std;
#define SC scanf
#define PR printf
#define SZ(v) ((int)(v).size())
typedef long long ll;
const int INF=0x3f3f3f3f;
int n;
string s[105];
int a[26],b[26];
int main(){
    ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=0;i<26;i++)a[i]=INF;
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=0;j<s[i].size();j++){
			b[s[i][j]-'a']++;
		}
		for(int j=0;j<26;j++)a[j]=min(a[j],b[j]);
	}
	for(int i=0;i<26;i++){
		for(int j=1;j<=a[i];j++){
			cout<<(char)(i+'a');
		}
	}
	cout<<endl;
	return 0;
}