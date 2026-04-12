#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 0;
int r, c;
char arr[105][105];
bool row[105], col[105];

int main(){
	IOS
	cin >> r >> c;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cin >> arr[i][j];
			if(arr[i][j]=='#'){
				row[i]=1;
				col[j]=1;
			}
		}
	}
	for(int i=1;i<=r;i++){
		if(row[i]){
			for(int j=1;j<=c;j++){
				if(col[j]){
					cout << arr[i][j];
				}
			}
			cout << endl;
		}
	}
}
