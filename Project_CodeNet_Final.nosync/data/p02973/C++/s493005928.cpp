#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const int MAX_N=1<<17;
int m, mx[2*MAX_N];
void init(int m_){
	m=1;
	while(m<m_) m<<=1;
	for(int i=1; i<=2*m-1; i++) mx[i]=0;
}

void update(int k, int a){
	k+=m;
	mx[k]=a;
	while(k>1){
		k>>=1;
		mx[k]=max(mx[2*k], mx[2*k+1]);
	}
}

int query(int a, int b){
	a+=m, b+=m;
	int ans=0;
	for(;a<b; a>>=1, b>>=1){
		if(b&1){
			b--;
			ans=max(ans, mx[b]);
		}
		if(a&1){
			ans=max(ans, mx[a]);
			a++;
		}
	}
	return ans;
}
int main()
{
    int n; cin>>n;
    int a[100010];
    vector<int> as(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
        as[i]=a[i];
    }
    sort(as.begin(), as.end());
    as.erase(unique(as.begin(), as.end()), as.end());
    for(int i=0; i<n; i++){
        a[i]=lower_bound(as.begin(), as.end(), a[i])-as.begin();
    }
    int c=as.size();
    init(c);
    int ans=0;
    for(int i=0; i<n; i++){
        int x=query(a[i], c);
        ans=max(ans, x+1);
        update(a[i], x+1);
    }
    cout<<ans<<endl;
    return 0;
}