#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0); ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int t;cin>>t;
		a.push_back(t);
	}
	sort(a.begin(), a.end());
	int l=a[a.size()-1], r = l;
	int i=0,j=a.size()-2;
	ll sum=0;
	while(i<j){
			int li=abs(l-a[i]),ri=abs(r-a[i]);
			int lj=abs(l-a[j]),rj=abs(r-a[j]);
			if(li>ri||lj>rj){
					if(li>lj){
							sum+=li;
							l=a[i++];
					}else{
							sum+=lj;
							l=a[j--];
					}
			}else{
					if(ri>rj){
							sum+=ri;
							r=a[i++];
					}else{
							sum+=rj;
							r=a[j--];
					}
			}
	}
	sum+=max(abs(l-a[i]),abs(r-a[i]));
	cout<<sum<<endl;
	
	return 0;
}