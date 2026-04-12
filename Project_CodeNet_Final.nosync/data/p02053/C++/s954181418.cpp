 
 #include<bits/stdc++.h>

using namespace std;
#define INF (1<<28)
#define DEKAI 1000000007
#define lp(i,n) for(int i=0;i<n;i++)
#define int long long

signed main(){
	int h,w;;
	cin>>h>>w;
	vector<int> a,b;
	lp(i,h){
		lp(j,w){
			char c;
			cin>>c;
			if(c=='B'){
				a.push_back(i+j);
				b.push_back(j-i);
			}
		}
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	cout<<max(abs(a[0]-a[a.size()-1]),abs(b[0]-b[b.size()-1]))<<endl;
	return 0;
}
