#include "bits/stdc++.h"
#define MAXN 100009
#define INF 1000000007
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define wr cout<<"----------------"<<endl;
#define ppb() pop_back()
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define my_little_dodge 46
#define debug(x)  cerr<< #x <<" = "<< x<<endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
int n;
int ans;
string s[111];
bool r[111],c[111];
int main()
{
    //~ freopen("file.in", "r", stdin);
    int m;
    scanf("%d",&n);scanf("%d",&m);
	for(int i=0;i<n;i++){
		cin>>s[i];
		for(int j=0;j<m;j++)
			if(s[i][j]=='#'){
				r[i]++;
				c[j]++;
			}
	}
//	for(int i=0;i<n;i++){
//		cerr << r[i] << ' ' << c[i] << endl;
//	}
	for(int i=0;i<n;i++){
		if(!r[i])
			continue;
		for(int j=0;j<m;j++)
			if(c[j]>0)
				cout << s[i][j];
		puts("");
	}			
	return 0;
}
