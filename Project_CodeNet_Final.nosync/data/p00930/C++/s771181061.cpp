#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>

using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename V> class segtree{
private:
    int n,sz; vector<V> node, lazy;
public:
    segtree(vector<V>& v){
        sz = (int)v.size(); n = 1;
        while(n < sz) n *= 2;
        node.resize(2*n-1); lazy.resize(2*n-1, 0);
        rep(i,sz) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = min(node[i*2+1],node[i*2+2]);
    }
    void eval(int k, int l, int r){
        if(lazy[k] != 0) {
            node[k] += lazy[k];
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k]; lazy[2*k+2] += lazy[k];
            }
            lazy[k] = 0;
        }
    }
    void range(int a, int b, V x, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b){
            lazy[k] += x; eval(k, l, r);
        }else{
            range(a, b, x, 2*k+1, l, (l+r)/2); range(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = min(node[2*k+1],node[2*k+2]);
        }
    }
    V query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return numeric_limits<V>::max();
        if(a <= l && r <= b) return node[k];
        V vl = query(a, b, 2*k+1, l, (l+r)/2), vr = query(a, b, 2*k+2, (l+r)/2, r);
        return min(vl,vr);
    }
    void print(){rep(i,sz)cout<<query(i,i+1)<< " ";cout<<endl;}
};


int main(){
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<int> v(n);
	set<int>st;
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			v[i]=1;
		}else{
			v[i] = -1;
			st.insert(i);
		}
	}
	for(int i=1;i<n;i++){
		v[i] += v[i-1];
	}
	segtree<int> sg(v);
	for(int i=0;i<m;i++){
		int a;
		cin >> a;
		a--;
		if(s[a]=='('){
			s[a] = ')';
			sg.range(a,n,-2);
			st.insert(a);
			int x = *st.begin();
			cout << x+1 << endl;
			s[x] = '(';
			sg.range(x,n,2);
			st.erase(st.begin());
		}else{
			s[a] = '(';
			st.erase(a);
			sg.range(a,n,2);
			int ok = n-1,ng =-1;
			while(abs(ok-ng)!=1){
				int mid = (ok+ng)/2;
				if(sg.query(mid,n)>=2){
					ok = mid;
				}else{
					ng = mid;
				}
			}
			sg.range(ok,n,-2);
			s[ok] = ')';
			st.insert(ok);
			cout << ok+1 << endl;
		}
	}





	return 0;
}
