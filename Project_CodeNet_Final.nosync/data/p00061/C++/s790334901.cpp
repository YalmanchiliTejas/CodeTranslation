#include "bits/stdc++.h"

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

#define dump(x)  cerr << #x << " = " << (x) << endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back

int main(){
	int t,p;
	char ch;
	vector<pii > data;
	while(cin>>t>>ch>>p){
		if(t==0 && p==0)break;
		data.pb(pii(50-p,t));
	}
	sort(all(data));
	int x;
	while(cin>>x){
		int c=0;
		int bef=0;
		rep(i,data.size()){
			if(bef!=data[i].first)c++;
			bef=data[i].first;
			if(data[i].second==x){
				cout<<c<<endl;
				break;
			}
		}
	}
	return 0;
}