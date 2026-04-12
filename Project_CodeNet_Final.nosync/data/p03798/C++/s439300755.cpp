#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define sz size
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORN(i,a,b) for(int i=a;i<=b;i++)
#define FORRN(i,a,b) for (int i = (a); i >= (b); i--)
#define FORR(i,a,b) for (int i = (a); i > (b); i--)
typedef unsigned long long ull;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); //Fast I/O
    cin.tie(0);
    cout.tie(0);
	//freopen("input.in","r",stdin);
	//freopen("output.out","w",stdout);

 	int n;
 	char s[100005];
 	bool A[100005];
 	cin >> n >> s;
 	s[n]=s[0];
 	s[n+1]=s[1];

 	FOR(i,0,4){
 		A[0]=i&1;
 		A[1]=(i>>1)&1;
 		for(int i=2;i<n+2;i++){
			if(A[i-1]^(s[i-1]=='o'))
				A[i]=A[i-2]^1;
			else 
				A[i]=A[i-2];
		}
 		if(A[n]==A[0] && A[n+1]==A[1]){
 			FOR(i,0,n){
 				if(A[i])
 					cout << 'S';
 				else
 					cout << "W";
 			}
 			return 0;
 		}
 	}

 	cout << -1 << endl;
    
    return 0;
}
