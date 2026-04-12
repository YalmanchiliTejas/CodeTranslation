#include <bits/stdc++.h>
#define ll unsigned long long int
#define pb push_back
using namespace std;
ll cnt,mini=1e9,maxi=-1;
ll n,m,k,x,a,b,c;
ll mini1=1e9,maxi1=-1,cnt1,cnt2,cnt3,ans,sum;
int main(){
ios_base::sync_with_stdio(0);
	// freopen (" .txt", "r", stdin);
	// freopen (" .txt", "w", stdout);
	string s;
	cin>>s;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='A'){
			cnt++;
		}
	}
	if(cnt==3 || cnt==0){
		cout<<"No";
	return 0;
	}
	cout<<"Yes";
}
//     *    *  *  ****    *    *   *
//    *	*   * *   *      * *   *   *
//   *****  **    ****  *****  *****
//   *   *  * *      *  *   *      *
//   *   *  *  *  ****  *   *  *****
 
//   ****  ****  *       *
//   *      **   *      * *
//   ****   **   *     *****
//      *   **   *     *   *
//   ****  ****  ****  *   *
