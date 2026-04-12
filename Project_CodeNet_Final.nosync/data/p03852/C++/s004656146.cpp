#include <bits/stdc++.h>
using namespace std;

#define rep(i,N) repf(i,0,N)
#define reps(i,N) repfs(i,0,N)
#define repf(i,a,b) for(int i=a;i<b;i++)
#define repfs(i,a,b) for(int i=a+1;i<=b;i++)
#define repr(i,N) for(int i=N-1;i>=0;i--)
#define reprs(i,N) for(int i=N;i>0;i--)

#define d(a) if(isDebugMode) cout<<#a<<"="<<a<<"."
#define d2(a,b) if(isDebugMode) cout<<#a<<"="<<a<<","<<#b<<"="<<b<<"."
#define d3(a,b,c) if(isDebugMode) cout<<#a<<"="<<a<<","<<#b<<"="<<b<<","<<#c<<"="<<c<<"."
#define d4(a,b,c,d) if(isDebugMode) cout<<#a<<"="<<a<<","<<#b<<"="<<b<<","<<#c<<"="<<c<<","<<#d<<"="<<d<<"."
#define da(arr,N){if(isDebugMode){rep(i,N){if(arr[i]==INF)printf("INF ");else cout<<arr[i]<<" ";} cout<<endl;}}
#define da2(arr,N,M){if(isDebugMode)rep(i,N){rep(j,M){if(arr[i][j]==INF)printf(" INF");else printf(" %3d",arr[i][j]);}cout<<endl;}}
#define pb push_back
#define pob pop_back

auto chmax =[](int &a,int b){ a = max(a, b);};
auto chmin =[](int &a,int b){ a = min(a, b);};

typedef long long ll;
typedef pair<int,int> P;
const int INF = 100000000;
const int MOD = 1000000007;
const int dx[4] = { 0, 1, 0,-1};
const int dy[4] = { 1, 0,-1, 0};

bool isDebugMode=1;
//--------------------------------------//
char c;

void solve(){
	cerr<<"fkdjflkjdlkfjewoifjewi;fjoiasjdfjsadflkj"<<endl;
	if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o')
		cout<<"vowel"<<endl;
	else
		cout<<"consonant"<<endl;
}

int main(){
	cin>>c;
	solve();
	return 0;
}
