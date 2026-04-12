//Written By Sourav Mondal
#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<int, nuint_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set; 
#define int long long
#define MOD 1000000007
#define what_is(x) cerr << #x << " is " << x << endl;
#define loop(i,a,n) for(int i=a;i<n;i++)

#define pb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(aint(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef pair<int, int> pt;
/*

//************FAST READ/WRITE*************
template<typename T = int>
inline T read() {
	T val = 0, sign = 1; char ch;
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-') sign = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		val = val * 10 + ch - '0';
	return sign * val;
}
*/

//**************************DSU PART*******************************
/*
#define MAX 110
int link[MAX], sz[MAX];


int findLink(int x) {
    while(x != link[x]) x = link[x];
    return x;
}
int isSameLink(int a, int b) {
    return findLink(a) == findLink(b);
}
void unite(int a, int b) {
    a = findLink(a);
    b = findLink(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
}
*/
/*
//************************Number theory**************************************
int power(int x, int y) {
  int ans = 1;

  while (y) {
    if (y & 1)
      ans = (ans * x) % MOD;

    y >>= 1;
    x = (x * x) % MOD;
  }

  return ans % MOD;
}

int mod_inverse(int a) {
  return power(a, MOD - 2);
}
*/
//Lambda Function
// auto is_even=[](auto n){return (n%2==0);};


/*
struct SegmentTreeNode {
	int prefixMaxSum, suffixMaxSum, maxSum, sum;
	
	void assignLeaf(int value) {
		prefixMaxSum = suffixMaxSum = maxSum = sum = value;
	}
	
	void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
		sum = left.sum + right.sum;
		prefixMaxSum = max(left.prefixMaxSum, left.sum + right.prefixMaxSum);
		suffixMaxSum = max(right.suffixMaxSum, right.sum + left.suffixMaxSum);
		maxSum = max(prefixMaxSum, max(suffixMaxSum, max(left.maxSum, max(right.maxSum, left.suffixMaxSum + right.prefixMaxSum))));
	}
	
	int getValue() {
		return maxSum;
	}
};

template<class T, class V>
class SegmentTree {
	SegmentTreeNode* nodes;
	int N;
	
public:
	SegmentTree(T arr[], int N) {
		this->N = N;
		nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
		buildTree(arr, 1, 0, N-1);
	}
	
	~SegmentTree() {
		delete[] nodes;
	}
	
	V getValue(int lo, int hi) {
		SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
		return result.getValue();
	}
	
	void update(int index, T value) {
		update(1, 0, N-1, index, value);
	}
	
private:	
	void buildTree(T arr[], int stIndex, int lo, int hi) {
		if (lo == hi) {
			nodes[stIndex].assignLeaf(arr[lo]);
			return;
		}
		
		int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		buildTree(arr, left, lo, mid);
		buildTree(arr, right, mid + 1, hi);
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
	
	SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi) {
		if (left == lo && right == hi)
			return nodes[stIndex];
			
		int mid = (left + right) / 2;
		if (lo > mid)
			return getValue(2*stIndex+1, mid+1, right, lo, hi);
		if (hi <= mid)
			return getValue(2*stIndex, left, mid, lo, hi);
			
		SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
		SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
		SegmentTreeNode result;
		result.merge(leftResult, rightResult);
		return result;
	}
	
	int getSegmentTreeSize(int N) {
		int size = 1;
		for (; size < N; size <<= 1);
		return size << 1;
	}
	
	void update(int stIndex, int lo, int hi, int index, T value) {
		if (lo == hi) {
			nodes[stIndex].assignLeaf(value);
			return;
		}
		
		int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		if (index <= mid)
			update(left, lo, mid, index, value);
		else
			update(right, mid+1, hi, index, value);
		
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
};
*/


int dp[3100][3100];	
signed main() {
	
	fastio();
//	#define LOCAL_DEFINE
	#ifdef LOCAL_DEFINE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	for(int i=n-1;i>=0;i--)
	{
		for(int j=i;j<n;j++)
		{
			if(i==j)
			{
				dp[i][j]=arr[i];
			}else{
				if(j!=0)
					dp[i][j]=max(arr[i]-dp[i+1][j],arr[j]-dp[i][j-1]);
				else
					dp[i][j]=arr[i]-dp[i+1][j];
			}	
		}
	}
	cout<<dp[0][n-1];
	return 0;		

	
}
