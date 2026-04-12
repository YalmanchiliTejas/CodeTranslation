#include<bits/stdc++.h>
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair



using namespace std;
typedef unsigned long long ull;
typedef vector<int>vi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int h,w;
	string a[1000];
	vector<string>b;
	cin >> h >> w;
	for(int i=0;i<h;i++){
		cin >> a[i];
	}	
	vi v,vv;	
	string comp1,comp2;
	for(int i=0;i<w;i++){
		comp1 += '.';
	}
	for(int i=0;i<h;i++){
		comp2 += '.';
	}
	

	for(int i=0;i < h;i++){
		if(a[i] == comp1){
			v.pb(i);
		}
	}
	
	string q;
	for(int i=0;i<w;i++){
		for(int j=0;j<h;j++){
//			cout << a[j][i];
			q += a[j][i];
		}
		b.pb(q);
		q.clear();
	}
	for(int i=0;i<b.size();i++){
		if(b[i] == comp2){
			vv.pb(i);	
		}
	}
	
	
	for(int i=0;i<h;i++){
		bool xx = false;
		for(int j=0;j<w;j++){
			if(find(v.begin(),v.end(),i) == v.end() && find(all(vv),j) == vv.end()){
				cout << a[i][j];
				xx = true;
			}
		}
		if(xx)cout << endl;
	}
	return 0;
	
}
