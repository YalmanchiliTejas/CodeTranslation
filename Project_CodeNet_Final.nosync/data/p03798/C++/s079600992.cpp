#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse
// struct Edge {
//   int to, id;
//   Edge(int a, int b): to(a), id(b) {}
// };

int v[100010];


int main(int argc, char const *argv[])
{
	int n;cin>>n;

	string s;cin>>s;

	// int v1[100010],v2[100010],v3[100010],v4[100010];




	rep(k,4) {
		bool ok = false;
		if (k==1) {
			v[0]=0;v[1]=1;
		} else if (k==2) {
			v[0]=1;v[1]=0;
		} else if (k==3) {
			v[0]=v[1]=1;
		}
		for (int i=1;i<n;i++) {
			if (i==n-1) {
				if (s[0]=='o'&&s[n-1]=='o') {
					if ((v[0]==0&&v[n-1]==0&&v[1]==v[n-1]&&v[n-2]==v[0])||(v[0]==0&&v[n-1]==1&&v[1]==v[n-1]&&v[n-2]!=v[0])||
						(v[0]==1&&v[n-1]==0&&v[1]!=v[n-1]&&v[n-2]==v[0])||(v[0]==1&&v[n-1]==1&&v[1]!=v[n-1]&&v[n-2]!=v[0])) ok = true;
				} else if (s[0]=='o'&&s[n-1]=='x') {
					if ((v[0]==0&&v[n-1]==0&&v[1]==v[n-1]&&v[n-2]!=v[0])||(v[0]==0&&v[n-1]==1&&v[1]==v[n-1]&&v[n-2]==v[0])||
						(v[0]==1&&v[n-1]==0&&v[1]!=v[n-1]&&v[n-2]!=v[0])||(v[0]==1&&v[n-1]==1&&v[1]!=v[n-1]&&v[n-2]==v[0])) ok = true;
				} else if (s[0]=='x'&&s[n-1]=='o') {
					if ((v[0]==0&&v[n-1]==0&&v[1]!=v[n-1]&&v[n-2]==v[0])||(v[0]==0&&v[n-1]==1&&v[1]!=v[n-1]&&v[n-2]!=v[0])||
						(v[0]==1&&v[n-1]==0&&v[1]==v[n-1]&&v[n-2]==v[0])||(v[0]==1&&v[n-1]==1&&v[1]==v[n-1]&&v[n-2]!=v[0])) ok = true;
				} else {
					if ((v[0]==0&&v[n-1]==0&&v[1]!=v[n-1]&&v[n-2]!=v[0])||(v[0]==0&&v[n-1]==1&&v[1]!=v[n-1]&&v[n-2]==v[0])||
						(v[0]==1&&v[n-1]==0&&v[1]==v[n-1]&&v[n-2]!=v[0])||(v[0]==1&&v[n-1]==1&&v[1]==v[n-1]&&v[n-2]==v[0])) ok = true;
				}
				if (ok) {
					rep(j,n) {
						if (v[j]==0) cout<<'S';
						else cout<<'W';
						if (j==n-1) cout<<endl;
					}
					return 0;
				}
			}
			if (s[i]=='o') {
				if (v[i]==0) v[i+1]=v[i-1];
				else v[i+1]=1-v[i-1];
			} else {
				if (v[i]==0) v[i+1]=1-v[i-1];
				else v[i+1]=v[i-1];
			}
		}
	}

	cout<<-1<<endl;


	// for (int i=1;i<n;i++) {
	// 	if (i==n-1) {
	// 		if (s[0]=='o') {
	// 			if (v1[1]==v1[n-1]) {
	// 				rep(j,n) {
	// 					cout<<v1[j];
	// 					if (j==n-1) cout<<endl;
	// 				}
	// 				return 0;
	// 			}
	// 		} else {
	// 			if (v1[0]!=v1[n-1]) {
	// 				rep(j,n) {
	// 					cout<<v1[j];
	// 					if (j==n-1) cout<<endl;
	// 				}
	// 				return 0;
	// 			}
	// 		}
	// 		break;
	// 	}
	// 	if (s[i]=='o') {
	// 		if (v1[i]==0) v1[i+1]=v1[i-1];
	// 		else v1[i+1]=1-v1[i-1];
	// 	} else {
	// 		if (v1[i]==0) v1[i+1]=1-v1[i-1];
	// 		else v1[i+1]=v1[i-1];
	// 	}
	// }

	// for (int i=1;i<n;i++) {
	// 	if (i==n-1) {
	// 		if (s[0]=='o') {
	// 			if (v2[1]==v2[n-1]) {
	// 				rep(j,n) {
	// 					cout<<v2[j];
	// 					if (j==n-1) cout<<endl;
	// 				}
	// 				return 0;
	// 			}
	// 		} else {
	// 			if (v2[0]!=v2[n-1]) {
	// 				rep(j,n) {
	// 					cout<<v2[j];
	// 					if (j==n-1) cout<<endl;
	// 				}
	// 				return 0;
	// 			}
	// 		}
	// 		break;
	// 	}
	// 	if (s[i]=='o') {
	// 		if (v2[i]==0) v2[i+1]=v2[i-1];
	// 		else v2[i+1]=1-v2[i-1];
	// 	} else {
	// 		if (v2[i]==0) v2[i+1]=1-v2[i-1];
	// 		else v2[i+1]=v2[i-1];
	// 	}
	// }

	// for (int i=1;i<n;i++) {
	// 	if (i==n-1) {
	// 		if (s[0]=='o') {
	// 			if (v3[1]==v3[n-1]) {
	// 				rep(j,n) {
	// 					cout<<v3[j];
	// 					if (j==n-1) cout<<endl;
	// 				}
	// 				return 0;
	// 			}
	// 		} else {
	// 			if (v3[0]!=v3[n-1]) {
	// 				rep(j,n) {
	// 					cout<<v3[j];
	// 					if (j==n-1) cout<<endl;
	// 				}
	// 				return 0;
	// 			}
	// 		}
	// 		break;
	// 	}
	// 	if (s[i]=='o') {
	// 		if (v3[i]==0) v3[i+1]=v3[i-1];
	// 		else v3[i+1]=1-v3[i-1];
	// 	} else {
	// 		if (v3[i]==0) v3[i+1]=1-v3[i-1];
	// 		else v3[i+1]=v3[i-1];
	// 	}
	// }

	// for (int i=1;i<n;i++) {
	// 	if (i==n-1) {
	// 		if (s[0]=='o') {
	// 			if (v4[1]==v4[n-1]) {
	// 				rep(j,n) {
	// 					cout<<v4[j];
	// 					if (j==n-1) cout<<endl;
	// 				}
	// 				return 0;
	// 			}
	// 		} else {
	// 			if (v4[0]!=v4[n-1]) {
	// 				rep(j,n) {
	// 					cout<<v4[j];
	// 					if (j==n-1) cout<<endl;
	// 				}
	// 				return 0;
	// 			}
	// 		}
	// 		break;
	// 	}
	// 	if (s[i]=='o') {
	// 		if (v4[i]==0) v4[i+1]=v4[i-1];
	// 		else v4[i+1]=1-v4[i-1];
	// 	} else {
	// 		if (v4[i]==0) v4[i+1]=1-v4[i-1];
	// 		else v4[i+1]=v4[i-1];
	// 	}
	// }


	return 0;
}