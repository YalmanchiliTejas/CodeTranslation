#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) { cin >> a[i]; }

	multiset<int> st;
	st.insert(-a[0]);
	for (int i = 1; i < N; ++i) {
		auto it = st.upper_bound(-a[i]);
		if (it != st.end()) {
			st.erase(it);
		}
		st.insert(-a[i]);
	}
	cout << st.size() << endl;

	return 0;
}
/*
#include <iostream>
#include <climits>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#define MAX 1000000007


using namespace std;
#define ll long long
#define dbg if(0)
#define ISRANGE(val,lo,hi) ((lo<=val)&&(val<hi))



int main(){
    ll ans,n;
    cin>>n;
    ll a;
    vector<ll> nlist;
    for(int i=0;i<n;i++){
        cin>>a;
        bool notfound=true;
        vector<ll>::iterator itr=nlist.begin();
        for(;itr!=nlist.end();itr++){
            if(a>*itr){
                *itr=a;
                notfound=false;
                break;
            }
        }
        if(notfound){
            nlist.push_back(a);
        }
    }

    cout <<nlist.size()<<endl;

    return 0;

}
*/