#include<iostream>
#include<vector>
using namespace std;
#define int long long int
class segtree
{
	public :
	int n;
	vector<int> tree;
	segtree(int N)
	{
		n=N;
		tree.resize(4*n+1,0);
	}
	void build_tree(int arr[],int start,int end,int index)
	{
		if(start==end)
		{
			tree[index]=arr[start];
			return ;
		}
		else
		{
			int mid=(start+end)/2;
			build_tree(arr,start,mid,2*index);
			build_tree(arr,mid+1,end,2*index+1);
			tree[index]=max(tree[2*index],tree[2*index+1]);
		}
	}
	int max_query(int start,int end,int left,int right,int index)
	{
		if(left>end||start>right)
		  return 0;
		if(start>=left&&end<=right)
		   return tree[index];
		else
		{
			int mid=(start+end)/2;
		    int x=max_query(start,mid,left,right,2*index);
		    int y=max_query(mid+1,end,left,right,2*index+1);
		    return max(x,y);
		}
	}
	void update(int start,int end,int point,int index,int val)
	{
		if(point>end||point<start)
		   return ;
		if(start==end)
		{
			tree[index]=val;
			return ;
		}
		else
		{
			int mid=(start+end)/2;
			update(start,mid,point,2*index,val);
			update(mid+1,end,point,2*index+1,val);
			tree[index]=max(tree[2*index],tree[2*index+1]);
		}
	}
	int binary_search(int start,int end,int val)
	{
		if(start>end)
		  return -1;
		else
		{
			int mid=(start+end)/2;
			int val2=max_query(0,n-1,start,mid,1);
			if(val2>=val)
			{
				int x=mid;
				int y=binary_search(start,mid-1,val);
				if(y==-1)
				  return x;
				else
				  return y;
			}
			else
			  return binary_search(mid+1,end,val);
		}
	}
};
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q;
	cin>>n>>q;
	segtree seg(n);
	int j,arr[n];
	for(j=0;j<n;j++)
	  cin>>arr[j];
	seg.build_tree(arr,0,n-1,1);
	while(q--)
	{
		int query;
		cin>>query;
		if(query==1)
		{
			int point,val;
			cin>>point>>val;
			point--;
			seg.update(0,n-1,point,1,val);
		}
		else if(query==2)
		{
			int left,right;
			cin>>left>>right;
			left--;
			right--;
			int answer=seg.max_query(0,n-1,left,right,1);
			cout<<answer<<endl;
		}
		else
		{
			int point,val;
			cin>>point>>val;
			point--;
			int answer=seg.binary_search(point,n-1,val);
			answer++;
			if(answer==0)
			  answer=n+1;
			cout<<answer<<endl;
		}
	}
}
