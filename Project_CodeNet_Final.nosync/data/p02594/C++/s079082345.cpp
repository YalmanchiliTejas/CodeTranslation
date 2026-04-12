#define r(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#include <bits/stdc++.h>
#include <cmath>
#include <fstream>
#define f first
#define endl "\n"
#define s second
#define pb push_back
#define ms(a,b) memset(a,b,sizeof(a))
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
typedef long long ll;
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
char _;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x;
	cin>>x;
	if(x>=30) cout << "Yes" << endl;
	else cout << "No" << endl;
		
	return 0;
}
