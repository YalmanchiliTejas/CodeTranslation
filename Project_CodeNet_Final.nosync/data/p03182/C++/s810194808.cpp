# include <bits/stdc++.h>
using namespace std;
# define MOD 1000000007
typedef long long ll;
class interval{
public:
    int left,right;
    ll val;
    interval(int left, int right, ll val){
        this->left = left;
        this->right = right;
        this->val = val;
    }
};
void update(ll tree[], ll lazy[], int i, int l, int r, int x, int y, ll val){
    if(l > r) return;
    if(lazy[i]){
        tree[i] += lazy[i];
        if(l != r){
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(x > r or l > y){
        return;
    }
    else if(x <= l and r <= y){
        tree[i] += val;
        if(l != r){
            lazy[2*i+1] += val;
            lazy[2*i+2] += val;
        }
        return;
    }
    int mid = l + (r-l)/2;
    update(tree, lazy, 2*i+1, l, mid, x, y, val);
    update(tree, lazy, 2*i+2, mid+1, r, x, y, val);
    tree[i] = max(tree[2*i+1], tree[2*i+2]);
}
// returns maximum value in range x-y
ll query(ll tree[], ll lazy[], int i, int l, int r, int x, int y){
    if(l > r) return 0;
    if(lazy[i]){
        tree[i] += lazy[i];
        if(l != r){
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(x > r or l > y){
        return 0;
    }
    else if(x <= l and r <= y){
        return tree[i];
    }
    int mid = l + (r-l)/2;
    ll left = query(tree, lazy, 2*i+1, l, mid, x, y);
    ll right = query(tree, lazy, 2*i+2, mid+1, r, x, y);
    return max(left, right);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	ll tree[4*n] = {};
	ll lazy[4*n] = {};
	unordered_map<int, vector<interval>> intervals;
	for(int i=0;i<m;i++){
	    int l, r;
	    ll v;
	    cin>>l>>r>>v;
	    intervals[r-1].push_back(interval(l-1, r-1, v));
	}
	for(int i=0;i<n;i++){
	    ll prev_max = query(tree, lazy, 0, 0, n-1, 0, i-1);
	    update(tree, lazy, 0, 0, n-1, i, i, prev_max);
	    for(int j=0;j<intervals[i].size();j++){
	        interval curr = intervals[i][j];
	        update(tree, lazy, 0, 0, n-1, curr.left, curr.right, curr.val);
	    }
	}
	ll ans = max(ll(0), query(tree, lazy, 0, 0, n-1, 0, n-1));
	cout<<ans;
	return 0;
}