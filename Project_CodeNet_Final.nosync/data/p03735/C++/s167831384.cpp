#include <bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
const int maxn = 2e5+5;
ll a[maxn],b[maxn];
int get_num(){
	int num = 0;
	char c;
	bool flag = false;
	while((c = getchar()) == ' ' || c == '\r' || c == '\n');
	if(c == '-')
		flag = true;
	else num = c - '0';
	while(isdigit(c = getchar()))
		num = (num<<3) + (num<<1) + c - '0';
	return (flag ? -1 : 1) * num;
}
ll ret = 0;
ll mxa,mna,mxb,mnb;
ll dmx,dmi;
ll id[maxn];
bool cmp(int x,int y){
	return a[x] < a[y];
}
int main(){
	n = get_num();
	mna = mnb = 1e9;
	for(int i = 1;i <= n;++i){
		id[i] = i;
		a[i] = get_num();
		b[i] = get_num();
		if(a[i] > b[i])swap(a[i],b[i]);
		mxa = max(mxa,a[i]);
		mna = min(mna,a[i]);
		mxb = max(mxb,b[i]);
		mnb = min(mnb,b[i]);
	}
	ret = (mxb - mnb) * (mxa - mna);
	dmx = 0;
	dmi = 1e9;
	sort(id+1,id+n+1,cmp);
	for(int i = 1;i <= n;++i){
		dmx = max(dmx,b[id[i]]);
		dmi = min(dmi,b[id[i]]);
		ret = min(ret,(ll)(max(dmx,a[id[n]])-min(dmi,a[id[i+1]])) * (mxb - mna));
	}
	cout << ret << endl;
	return 0;
}