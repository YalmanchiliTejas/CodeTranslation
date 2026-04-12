#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> mp;
#define inf 1e9


int main(){
	ll n;
	cin>>n;
	vector<ll> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a.begin(),a.end());
	list<ll> l1,l2;
	for(int i=0;i<n;i++){
		l1.push_back(a[i]);
		l2.push_back(a[i]);
	}
	ll res1 = 0,res2 = 0;
	ll sv1 = a[n-1],lv1 = a[n-1];
	ll sv2 = a[0],lv2= a[0];
	l1.pop_back();
	l2.pop_front();
	int mode = 1;
	while(!l1.empty()){
		if(mode==1){
			ll tmp1 = l1.front(),tmp2 = l2.back();
			res1 += abs(sv1-tmp1);
			res2 += abs(sv2-tmp2);
			l1.pop_front();
			l2.pop_back();
			sv1 = tmp1;
			sv2 = tmp2;
			if(!l1.empty()){
				tmp1 = l1.front(),tmp2 = l2.back();
				res1 += abs(lv1-tmp1);
				res2 += abs(lv2-tmp2);
				l1.pop_front();
				l2.pop_back();
				lv1 = tmp1;
				lv2 = tmp2;
			}
		}else{
			ll tmp1 = l1.back(),tmp2 = l2.front();
			res1 += abs(sv1-tmp1);
			res2 += abs(sv2-tmp2);
			l1.pop_back();
			l2.pop_front();
			sv1 = tmp1;
			sv2 = tmp2;
			if(!l1.empty()){
				tmp1 = l1.back(),tmp2 = l2.front();
				res1 += abs(lv1-tmp1);
				res2 += abs(lv2-tmp2);
				l1.pop_back();
				l2.pop_front();
				lv1 = tmp1;
				lv2 = tmp2;
			}

		}
		mode = (mode+1)%2;
	}
	cout<< max(res1,res2 ) <<endl;
	return 0;
}
