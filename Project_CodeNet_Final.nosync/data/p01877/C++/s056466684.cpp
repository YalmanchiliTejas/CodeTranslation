#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_SIZE=2000000;
ll segMin[MAX_SIZE - 1],segMax[MAX_SIZE - 1], segAdd[MAX_SIZE - 1];
int n,N=1;

//??????[a, b)??????x???????????????.
void add(int a, int b, int x, int k = 0, int l = 0, int r = N)
{
	if (r <= a || b <= l) return;
	if (a <= l && r <= b){
		segAdd[k] += x;
		while (k){
			k = (k - 1) / 2;
			segMin[k] = min(segMin[k * 2 + 1] + segAdd[k * 2 + 1], segMin[k * 2 + 2] + segAdd[k * 2 + 2]);
			segMax[k] = max(segMax[k * 2 + 1] + segAdd[k * 2 + 1], segMax[k * 2 + 2] + segAdd[k * 2 + 2]);
		}
		return;
	}
	
	add(a, b, x, k * 2 + 1, l, (l + r) / 2);
	add(a, b, x, k * 2 + 2, (l + r) / 2, r);
}

ll getMin(int a, int b, int k = 0, int l = 0, int r = N)
{
	if (r <= a || b <= l) return (LLONG_MAX);
	if (a <= l && r <= b) return (segMin[k] + segAdd[k]);
	ll left = getMin(a, b, k * 2 + 1, l, (l + r) / 2);
	ll right = getMin(a, b, k * 2 + 2, (l + r) / 2, r);
	return (min(left, right) + segAdd[k]);
}
ll getMax(int a, int b, int k = 0, int l = 0, int r = N)
{
	if (r <= a || b <= l) return (-LLONG_MAX);
	if (a <= l && r <= b) return (segMax[k] + segAdd[k]);
	ll left = getMax(a, b, k * 2 + 1, l, (l + r) / 2);
	ll right = getMax(a, b, k * 2 + 2, (l + r) / 2, r);
	return (max(left, right) + segAdd[k]);
}
void dump() {
  for(int i=0;i<n/2;i++) {
    cout<<i<<": "<<getMin(i,i+1)<<", "<<getMax(i,i+1)<<endl;
  }
}
int main() {
  cin >> n;
  while(N<n) N<<=1;
  ll a[n];
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<n/2; i++) add(i,i+1,a[i]-a[n-1-i]);
  int m;
  cin >> m;
  while(m--) {
    int x,y,z;
    cin >> x >> y >> z;
    x--,y--;
    if(y<n/2) add(x,y+1,z);
    else if(n/2<=x) {
      x=n-x-1;
      y=n-y-1;
      add(y,x+1,-z);
    } else {
      y=n-y-1;
      //cout<<__LINE__<<": "<<x<<", "<<y<<endl;
      add(x,n/2+1,z);
      add(y,n/2+1,-z);
    }
    //dump();
    ll mi=getMin(0,n/2+1);
    ll ma=getMax(0,n/2+1);
    if(!mi&&!ma) cout << 1 << endl;
    else cout << 0 << endl;
  }
  return 0;
}