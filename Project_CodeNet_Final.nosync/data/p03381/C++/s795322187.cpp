#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
map<int,int> pos;
int main()
{

	ios_base:: sync_with_stdio(false); cin.tie(0);
	int n; cin>>n;
	vector<int> a(n+1),b(n+1);
	for(int i=1; i<=n; i++) {
		cin>>b[i];
		a[i]=b[i];
	}
	sort(a.begin()+1,a.end());
	int cur=n/2;
	for(int i=1; i<=n; i++) {
		if(i<=cur) {
			pos[a[i]]=a[cur+1];
		}
		else{
			pos[a[i]]=a[cur];
		}
	}

	for(int i=1; i<=n; i++) {
		cout<<pos[b[i]]<<endl;
	}


	return 0;
}
