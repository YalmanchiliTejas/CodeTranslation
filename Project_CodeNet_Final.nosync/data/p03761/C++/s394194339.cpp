//Sani buyuk Osman Pasa Plevneden cikmam diyor.
//FatihSultanMehmedHan
//Abdulhamid Han Elmuzaffer Daima
//Bismillahirrahmanirrahim

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long int lo;
typedef pair< int,int > PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR for(int i=0;i<n;i++)
#define mid (start+end)/2
#define ort (bas+son)/2

const lo MAX = -1000000000000000000; 
const lo MIN = 1000000000000000000; 
const lo inf = 1000000000; 
const lo KOK = 100000; 
const lo LOG = 30; 
const lo li = 100005; 
const lo mod = 1000000007; 

int n,m,cev,b,a[li],k,mpp[100][100];
string s;
vector<int> v;

inline int solve(){
	int t;cin>>t;
	n=t;
	while(t--){
		//~ cout<<t<<endl;
		cin>>s;
		for(int i=0;i<(int)s.size();i++){
			mpp[t][s[i]-'a']++;
		}
	}
	for(int j='a'-'a';j<='z'-'a';j++){
		int mn=inf;
		FOR{
			mn=min(mn,mpp[i][j]);
		}
		for(int i=1;i<=mn;i++){
			//~ cout<<"*(\n";
			//~ cout<<j<<endl;
			cout<<(char)('a'+j);
		}
	}
	return 0;
}

int main(void){
	solve();
	
	return 0;
}
