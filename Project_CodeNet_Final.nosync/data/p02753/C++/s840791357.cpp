#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define vii vector <int>
#define vll vector <long long>
#define pii pair <int, int>
#define repDown(i,a,n) for(int i=n;i>a;i--)
#define rep(i,a,n) for(int i=a;i<n;i++)
#define endl '\n'
#define mem(a,b) memset(a, b, sizeof a)
#define max(a,b,c) max(c, min(a,b))
#define min(a,b,c) min(c, min(a,b))
ll mod=1000000007;
using namespace std;
void print(vector <int> &arr){
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	
	cout<<endl;
}
void printll(vector <ll> &arr){
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	
	cout<<endl;
}

int main(){
/////////////////////////////////////////////////////////////////////
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	cerr.tie(nullptr);
//For fast IO
///////////////////////////////////////////////////////////////////// 

	string s;
	cin>>s;
	if(s[0]=='A' && s[1]=='A' && s[2]=='A') cout<<"No"<<endl;
	else if(s[0]=='B' && s[1]=='B' && s[2]=='B') cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;
}