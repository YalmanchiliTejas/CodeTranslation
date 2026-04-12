#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Segtree{
	int data[1<<19], base=1<<18;
	void add(int p, int v){
		for(p+=base-1; p; p/=2)
			data[p]+=v;
	}
	int getKth(int k){
		int now=1;
		while(now < base){
			if(data[now*2]>=k) now*=2;
			else{
				k -= data[now*2];
				now = now*2+1;
			}
		}
		return now-(base-1);
	}
} seg;

int a[200010];
vector<int> comp;
int O2N(int Org){ return lower_bound(comp.begin(), comp.end(), Org)-comp.begin()+1;}
int N2O(int New){ return comp[New-1]; }

int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &a[i]), comp.push_back(a[i]);;
	sort(comp.begin(), comp.end());
	comp.resize(distance(comp.begin(), unique(comp.begin(), comp.end())));
	for(int i=1; i<=n; i++){
		a[i] = O2N(a[i]);
		seg.add(a[i], 1);
	}
	for(int i=1; i<=n; i++){
		seg.add(a[i], -1);
		int val = seg.getKth(n/2);
		printf("%d\n", N2O(val));
		seg.add(a[i], 1);
	}
	return 0;
}
